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

int		add_link(t_room **farm, char *room, char *link)
{
	int	i;
	int j;
	int k;
	int rooms;

	rooms = -1;
	if (ft_strequ(room, link))
		return (1);
	while (farm[++rooms])
		;
	i = -1;
	while (farm[++i])
	{
		if (ft_strequ(room, farm[i]->name))
		{
			if(!(farm[i]->edges))
				farm[i]->edges = (t_room**)ft_memalloc(sizeof(t_room*) * (rooms + 1));
			k = -1;
			while (farm[i]->edges[++k])
				if (ft_strequ(farm[i]->edges[k]->name, link))
					return (1);
			k = -1;
			j = -1;
			while (farm[++j])
			{
				if (ft_strequ(link, farm[j]->name))
				{
					k = 0;
					while (farm[i]->edges[k])
						k++;
					farm[i]->edges[k] = farm[j];
					farm[i]->edges[k + 1] = 0;
					return (1);
				}
			}
		}
	}
	return (0);
}

int		get_view(t_farm *farm)
{
	char 	**split = 0;
	int 	valid;
	int		n_rooms = 0;
	int 	lines = 5;
	int 	i;
	int 	fd;

	valid = 1;
	i = -1;
	farm->view = (char**)ft_memalloc(sizeof(char*) * (lines + 1));
	fd = 0;
	while (valid && (get_next_line(fd, &farm->view[++i]) > 0))
	{
		if (i == lines)
		{
			lines *= 2;
			farm->view = (char**)ft_realloc(farm->view, sizeof(char*) * (lines + 1));
		}
		if ((farm->view[i][0] == '#' && farm->view[i][1] != '#') ||
		(farm->view[i][0] == '#' && farm->view[i][1] == '#' && farm->view[i][2] != '#'))
			;
		else if (!ft_strchr(farm->view[i], ' ') && !n_rooms && !farm->ants)
			farm->ants = ft_atoi(farm->view[i]);
		else if (ft_strchr(farm->view[i], ' '))
		{
			split = ft_strsplit(farm->view[i], ' ');
			if (!split[0] || !split[1] || !split[2] ||
				(split[3] && !(split[3][0] == '#' && split[3][1] != '#')))
				break ;
			n_rooms++;
		}
		else if (ft_strchr(farm->view[i], '-'))
		{
			split = ft_strsplit(farm->view[i], '-');
			if (!split[0] || !split[1] || split[2])
				break ;
		}
		else
			valid = 0;
		if (split)
			ft_memdel_arr((void***)&split);
	}
	farm->view[i] = 0;
	return (n_rooms);
}

t_room	**get_rooms(t_farm *farm)
{
	t_room	**rooms;
	char 	*line;
	char 	**split = 0;
	int 	start = 0;
	int 	end = 0;
	int 	i;
	int 	j;

	i = 0;
	j = -1;
	rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (get_view(farm) + 1));
	if (farm->ants < 1)
	{
		ft_printf("ERROR: no ants!\n");
		exit(0);
	}
	while ((line = farm->view[++j]))
	{
		if (ft_strequ(line, "##start"))
			start++;
		else if (ft_strequ(line, "##end"))
			end++;
		else if ((line[0] == '#' && line[1] != '#') ||
				(line[0] == '#' && line[1] == '#' && line[2] != '#'))
			 ;
		else if (ft_strchr(line, ' '))
		{
			split = ft_strsplit(line, ' ');
			rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
			rooms[i]->name = ft_strdup(split[0]);
			rooms[i]->index = ft_itoa(i);
			rooms[i]->x = ft_atoi(split[1]);
			rooms[i]->y = ft_atoi(split[2]);
			if (start == 1)
			{
				rooms[i]->status = 1;
				start++;
			}
			else if (end == 1)
			{
				rooms[i]->status = 2;
				end++;
			}
			i++;
		}
		else if (ft_strchr(line, '-'))
		{
			split = ft_strsplit(line, '-');
			if (!(add_link(rooms, split[0], split[1])))
			{
				ft_printf("ERROR: wrong link!\n");
				exit(0);
			}
			add_link(rooms, split[1], split[0]);
		}
		if (split)
			ft_memdel_arr((void***)&split);
	}
	rooms[i] = 0;
	if (start != 2 || end != 2)
	{
		ft_printf("ERROR: wrong number of ##start/##end!\n");
		exit(0);
	}
	return (rooms);
}

t_farm	*make_farm()
{
	t_farm	*farm;
	int 	i;

	i = -1;
	farm = (t_farm*)ft_memalloc(sizeof(t_farm));
	farm->rooms = get_rooms(farm);
	if (!farm->rooms[0])
	{
		ft_printf("ERROR: no rooms!\n");
		exit(0);
	}
	while (farm->rooms[++i])
		;
	farm->rooms_n = i;
	i = -1;
	while (farm->rooms[++i])
		if (farm->rooms[i]->status == 1)
			farm->s_index = ft_itoa(i);
		else if (farm->rooms[i]->status == 2)
			farm->e_index = ft_itoa(i);
	if (!farm->s_index || !farm->e_index)
	{
		ft_printf("ERROR: no start or exit!\n");
		exit(0);
	}
	return (farm);
}
