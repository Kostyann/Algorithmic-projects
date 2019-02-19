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

int		ft_strchrnum(const char *s, int c)
{
	char	q;
	int		num;

	q = c;
	num = 0;
	while (*s)
	{
		if (*s == q)
			num++;
		s++;
	}
	if (*s == q)
		num++;
	return (num);
}

int		line_analyze(t_farm *farm, char *line, int *n_rooms, char ***split)
{
	if ((line[0] == '#' && line[1] != '#') ||
		(line[0] == '#' && line[1] == '#' && line[2] != '#'))
		;
	else if (!ft_strchr(line, ' ') && !(*n_rooms) && !farm->ants)
		farm->ants = ft_atoi(line);
	else if (ft_strchr(line, ' '))
	{
		*split = ft_strsplit(line, ' ');
		if (!(*split)[0] || (*split)[0][0] == 'L' ||
			!(*split)[1] || !(*split)[2] ||
			((*split)[3] && !((*split)[3][0] == '#' && (*split)[3][1] != '#')))
			return (0);
		(*n_rooms)++;
	}
	else if (ft_strchr(line, '-') && (ft_strchrnum(line, '-') == 1)
				&& (*split = ft_strsplit(line, '-')))
	{
		if (!(*split)[0] || !(*split)[1] || (*split)[2])
			return (0);
	}
	else
		return (0);
	if (*split)
		ft_memdel_arr((void***)split);
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
		if (!(line_analyze(farm, farm->view[i], &n_rooms, &split)))
			break ;
	}
	if (split)
		ft_memdel_arr((void***)&split);
	ft_strdel(&farm->view[i]);
	return (n_rooms);
}

void	get_graph(t_farm *farm)
{
	char	**split;
	int		start;
	int		end;
	int		j;

	split = 0;
	start = 0;
	end = 0;
	farm->rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	j = room_or_comment(farm, &start, &end, split);
	if (start != 999 || end != 999)
	{
		ft_printf("ERROR1!\n");
		exit(0);
	}
	link_or_comment(farm, j, split);
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
		ft_printf("ERROR2!\n");
		exit(0);
	}
	get_graph(farm);
	while (farm->rooms[++i])
		if (farm->rooms[i]->status == 1)
			farm->s_index = farm->rooms[i]->index;
		else if (farm->rooms[i]->status == 2)
			farm->e_index = farm->rooms[i]->index;
	return (farm);
}
