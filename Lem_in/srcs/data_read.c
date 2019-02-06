/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:15:13 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/30 16:15:16 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	linkage(t_farm *farm, int i, int j)
{
	int k;

	k = 0;
	while (farm->rooms[i]->edges[k])
		k++;
	farm->rooms[i]->edges[k] = farm->rooms[j];
	farm->rooms[i]->edges[k + 1] = 0;
	if (!(farm->rooms[j]->edges))
		farm->rooms[j]->edges = (t_room **)
				ft_memalloc(sizeof(t_room *) * (farm->rooms_n + 1));
	k = 0;
	while (farm->rooms[j]->edges[k])
		k++;
	farm->rooms[j]->edges[k] = farm->rooms[i];
	farm->rooms[j]->edges[k + 1] = 0;
}

int		add_link(t_farm *farm, char *room, char *link)
{
	int i;
	int j;
	int k;

	if (ft_strequ(room, link))
		return (1);
	i = -1;
	while (farm->rooms[++i] && (k = -1) == -1)
		if (ft_strequ(room, farm->rooms[i]->name) && (j = -1) == -1)
		{
			if (!(farm->rooms[i]->edges))
				farm->rooms[i]->edges = (t_room **)ft_memalloc(sizeof(t_room *)
						* (farm->rooms_n + 1));
			while (farm->rooms[i]->edges[++k])
				if (ft_strequ(farm->rooms[i]->edges[k]->name, link))
					return (1);
			while (farm->rooms[++j])
				if (ft_strequ(link, farm->rooms[j]->name))
				{
					linkage(farm, i, j);
					return (1);
				}
		}
	return (0);
}

int		line_analyze(t_farm *farm, char *line, int *n_rooms, char **split)
{
	if ((line[0] == '#' && line[1] != '#') ||
		(line[0] == '#' && line[1] == '#' && line[2] != '#'))
		;
	else if (!ft_strchr(line, ' ') && !(*n_rooms) && !farm->ants)
		farm->ants = ft_atoi(line);
	else if (ft_strchr(line, ' '))
	{
		split = ft_strsplit(line, ' ');
		if (!split[0] || !split[1] || !split[2] ||
			(split[3] && !(split[3][0] == '#' && split[3][1] != '#')))
			return (0);
		(*n_rooms)++;
	}
	else if (ft_strchr(line, '-') && (split = ft_strsplit(line, '-')))
	{
		if (!split[0] || !split[1] || split[2])
			return (0);
	}
	else
		return (0);
	if (split)
		ft_memdel_arr((void***)&split);
	return (1);
}

int		get_view(t_farm *farm)
{
	int		n_rooms;
	int		lines;
	char	**split;
	int		i;

	n_rooms = 0;
	lines = 5;
	split = 0;
	i = -1;
	farm->view = (char**)ft_memalloc(sizeof(char*) * (lines + 1));
	while ((get_next_line(0, &farm->view[++i]) > 0))
	{
		if (i == lines)
		{
			lines *= 2;
			farm->view = (char**)ft_realloc(farm->view, sizeof(char*)
			* (lines + 1));
		}
		if (!(line_analyze(farm, farm->view[i], &n_rooms, split)))
			break ;
	}
	ft_strdel(&farm->view[i]);
	return (n_rooms);
}

/*int		room_or_comment(char *line, int *start, int *end)
{
	if (ft_strequ(line, "##start"))
		(*start)++;
	else if (ft_strequ(line, "##end"))
		(*end)++;
	else if ((line[0] == '#' && line[1] != '#') ||
			 (line[0] == '#' && line[1] == '#' && line[2] != '#'))
		;
	else if (ft_strchr(line, ' '))
	{
		split = ft_strsplit(line, ' ');
		farm->rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
		farm->rooms[i]->name = ft_strdup(split[0]);
		farm->rooms[i]->index = ft_itoa(i);
		farm->rooms[i]->x = ft_atoi(split[1]);
		farm->rooms[i]->y = ft_atoi(split[2]);
		if (*start == 1)
			farm->rooms[i]->status = (*start)++;
		else if (*end == 1)
			farm->rooms[i]->status = ++(*end);
		i++;
	}
} */

void	get_rooms(t_farm *farm)
{
	char	**split;
	int		start;
	int		end;
	int		i;
	int		j;

	split = 0;
	start = 0;
	end = 0;
	i = 0;
	j = -1;
	farm->rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	while (farm->view[++j])
	{
		if (ft_strequ(farm->view[j], "##start"))
			start++;
		else if (ft_strequ(farm->view[j], "##end"))
			end++;
		else if ((farm->view[j][0] == '#' && farm->view[j][1] != '#') ||
				(farm->view[j][0] == '#' && farm->view[j][1] == '#' &&
				farm->view[j][2] != '#'))
			;
		else if (ft_strchr(farm->view[j], ' '))
		{
			split = ft_strsplit(farm->view[j], ' ');
			farm->rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
			farm->rooms[i]->name = ft_strdup(split[0]);
			farm->rooms[i]->index = ft_itoa(i);
			farm->rooms[i]->x = ft_atoi(split[1]);
			farm->rooms[i]->y = ft_atoi(split[2]);
			if (start == 1)
				farm->rooms[i]->status = start++;
			else if (end == 1)
				farm->rooms[i]->status = ++end;
			i++;
		}
		else if (ft_strchr(farm->view[j], '-'))
		{
			split = ft_strsplit(farm->view[j], '-');
			if (!(add_link(farm, split[0], split[1])))
			{
				ft_printf("ERROR: wrong link!\n");
				exit(0);
			}
		}
		if (split)
			ft_memdel_arr((void***)&split);
	}
	farm->rooms[i] = 0;
	if (start != 2 || end != 2)
	{
		ft_printf("ERROR: wrong number of ##start/##end!\n");
		exit(0);
	}
}

t_farm	*make_farm(void)
{
	t_farm	*farm;
	int		i;

	i = -1;
	farm = (t_farm*)ft_memalloc(sizeof(t_farm));
	farm->rooms_n = get_view(farm);
	if (farm->ants < 1 || farm->rooms_n < 1)
	{
		ft_printf("ERROR: no ants or rooms!\n");
		exit(0);
	}
	get_rooms(farm);
	while (farm->rooms[++i])
		if (farm->rooms[i]->status == 1)
			farm->s_index = farm->rooms[i]->index;
		else if (farm->rooms[i]->status == 2)
			farm->e_index = farm->rooms[i]->index;
	return (farm);
}
