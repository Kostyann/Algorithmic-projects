/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:40:04 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/02/06 15:40:06 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	linking(t_farm *farm, int i, int j)
{
	int k;

	k = farm->rooms[i]->edges_n;
	farm->rooms[i]->edges[k] = farm->rooms[j];
	farm->rooms[i]->edges[k + 1] = 0;
	farm->rooms[i]->edges_n++;
	if (!(farm->rooms[j]->edges))
		farm->rooms[j]->edges = (t_room **)
				ft_memalloc(sizeof(t_room *) * (farm->rooms_n + 1));
	k = farm->rooms[j]->edges_n;
	farm->rooms[j]->edges[k] = farm->rooms[i];
	farm->rooms[j]->edges[k + 1] = 0;
	farm->rooms[j]->edges_n++;
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
					linking(farm, i, j);
					return (1);
				}
		}
	return (0);
}

void	add_room(t_room *room, char **split, int *start, int *end)
{
	room->name = ft_strdup(split[0]);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	if (*start == 1)
	{
		room->status = *start;
		*start = 999;
	}
	else if (*end == 1)
	{
		room->status = (*end) + 1;
		*end = 999;
	}
}

int		room_or_comment(t_farm *farm, int *st, int *end, char **split)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (farm->view[++j] && !(ft_strchr(farm->view[j], '-')))
		if (ft_strequ(farm->view[j], "##start") && (*end == 0 || *end == 999))
			(*st)++;
		else if (ft_strequ(farm->view[j], "##end") && (*st == 999 || *st == 0))
			(*end)++;
		else if ((farm->view[j][0] == '#' && farm->view[j][1] != '#') ||
				(farm->view[j][0] == '#' && farm->view[j][1] == '#' &&
				farm->view[j][2] != '#'))
			;
		else if (ft_strchr(farm->view[j], ' '))
		{
			split = ft_strsplit(farm->view[j], ' ');
			farm->rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
			farm->rooms[i]->index = ft_itoa(i);
			add_room(farm->rooms[i], split, st, end);
			i++;
			ft_memdel_arr((void***)&split);
		}
	farm->rooms[i] = 0;
	return (j);
}

int		link_or_comment(t_farm *farm, int j, char **split)
{
	while (farm->view[j])
	{
		if ((farm->view[j][0] == '#' && farm->view[j][1] != '#') ||
			(farm->view[j][0] == '#' && farm->view[j][1] == '#' &&
			farm->view[j][2] != '#'))
			;
		else
		{
			split = ft_strsplit(farm->view[j], '-');
			if (!(add_link(farm, split[0], split[1])))
			{
				ft_printf("ERROR3!\n");
				exit(0);
			}
			ft_memdel_arr((void***)&split);
		}
		j++;
	}
	return (j);
}
