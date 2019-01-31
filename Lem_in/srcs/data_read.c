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

void	add_link(t_room **farm, char *room, char *link)
{
	int	i;
	int j;
	int k;
	int rooms;

	rooms = -1;
	while (farm[++rooms])
		;
	i = -1;
	while (farm[++i])
	{
		if (ft_strequ(room, farm[i]->name))
		{
			j = -1;
			if(!(farm[i]->edges))
				farm[i]->edges = (t_room**)ft_memalloc(sizeof(t_room*) * (rooms + 1));
			k = -1;
			while (farm[i]->edges[++k])
				if (ft_strequ(farm[i]->edges[k]->name, link))
					return ;
			k = -1;
			while (farm[++j])
			{
				if (ft_strequ(link, farm[j]->name))
				{
					k = 0;
					while (farm[i]->edges[k])
						k++;
					farm[i]->edges[k] = farm[j];
					farm[i]->edges[k + 1] = 0;
					return ;
				}
			}
		}
	}
}

t_room	**get_rooms()
{
	t_room	**rooms;
	char	*line;
	char 	**split = 0;
	int 	valid;
	int 	ants = 0;
	int 	start = 0;
	int 	end = 0;
	int 	nodes = 5;
	int 	i;
	int 	fd;

	valid = 1;
	i = -1;
	rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (nodes + 1));
	fd = 0;
	while ((get_next_line(fd, &line) > 0) && valid)
	{
		if (i == nodes)
		{
			nodes *= 2;
			rooms = (t_room**)ft_realloc(rooms, sizeof(t_room*) * (nodes + 1));
		}
		if (i == -1)
		{
			ants = ft_atoi(line);
			i++;
		}
		else if (ft_strequ(line, "##start"))
			start = 1;
		else if (ft_strequ(line, "##end"))
			end = 1;
		else if (ft_strchr(line, ' '))
		{
			rooms[i] = (t_room*)ft_memalloc(sizeof(t_room) + 1);
			split = ft_strsplit(line, ' ');
			rooms[i]->name = ft_strdup(split[0]);
			rooms[i]->index = ft_itoa(i);
			//	ft_printf("name %d - %s\n", i, rooms[i]->name);
			rooms[i]->x = ft_atoi(split[1]);
			rooms[i]->y = ft_atoi(split[2]);
			if (start)
			{
				rooms[i]->status = 1;
				rooms[i]->ants = ants;
				start = 0;
			}
			else if (end)
			{
				rooms[i]->status = 2;
				end = 0;
			}
			i++;
		}
		else if (ft_strchr(line, '-'))
		{
			split = ft_strsplit(line, '-');
			add_link(rooms, split[0], split[1]);
			add_link(rooms, split[1], split[0]);
			//	ft_printf("_______________________\n");
		}
		else
			valid = 0;
		if (split)
			ft_memdel_arr((void***)&split);
		free(line);
	}
	rooms[i] = 0;
	return (rooms);
}

t_farm	*make_farm()
{
	t_farm	*farm;
	t_room	**rooms;
	int 	i;

	i = -1;
	rooms = get_rooms();
	farm = (t_farm*)ft_memalloc(sizeof(t_farm));
	farm->rooms = rooms;
	while (farm->rooms[++i])
		;
	farm->rooms_n = i;
	i = -1;
	while (farm->rooms[++i])
		if (farm->rooms[i]->status == 1)
			farm->s_index = ft_itoa(i);
		else if (farm->rooms[i]->status == 2)
			farm->e_index = ft_itoa(i);
	farm->ants = farm->rooms[ft_atoi(farm->s_index)]->ants;
	return (farm);
}
