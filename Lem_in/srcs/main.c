/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:34:19 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/22 16:34:21 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"
#include <fcntl.h>

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
	//	ft_printf("lala0\n");
	//	ft_printf("room = %s, link = %s, name%d = %s\n", room, link, i, farm[i]->name);
		if (ft_strequ(room, farm[i]->name))
		{
	//		ft_printf("lala1\n");
			j = -1;
			if(!(farm[i]->edges))
				farm[i]->edges = (t_room**)ft_memalloc(sizeof(t_room*) * (rooms + 1));
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
	fd = open("test.txt", O_RDONLY);
//	fd = 1;
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
			rooms[i] = (t_room*)ft_memalloc(sizeof(t_room));
			split = ft_strsplit(line, ' ');
			rooms[i]->name = ft_strdup(split[0]);
			rooms[i]->index = i;
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

t_farm	*make_farm(t_room **rooms)
{
	t_farm	*farm;
	int 	i;

	i = -1;
	farm = (t_farm*)ft_memalloc(sizeof(t_farm));
	farm->rooms = rooms;
	while (farm->rooms[++i])
		 ;
	farm->quantity = i;
	i = -1;
	while (farm->rooms[++i])
		if (farm->rooms[i]->status == 1)
			farm->s_index = i;
		else if (farm->rooms[i]->status == 2)
			farm->e_index = i;
	return (farm);
}

void	print_farm(t_farm *farm)
{
	int i = -1;
	int j;

	ft_printf("Number of rooms - %d\n", farm->quantity);
	ft_printf("Start index - %d\n", farm->s_index);
	ft_printf("End index - %d\n", farm->e_index);
	while (farm->rooms[++i])
	{
		j = -1;
		ft_printf("%-3d ", farm->rooms[i]->index);
		ft_printf("%-6s ", farm->rooms[i]->name);
		while (farm->rooms[i]->edges[++j])
			ft_printf("->%-7s", farm->rooms[i]->edges[j]->name);
	//	ft_printf("  ants = %d", farm->rooms[i]->ants);
		ft_printf("\n");
	}
}

void	print_paths(t_path **paths)
{
	int	i = -1;
	int j = -1;

	while (paths[++j])
	{
		i = -1;
		ft_printf("Depth %d\n", paths[j]->depth);
		ft_printf("Path: ");
		while (paths[j]->path[++i])
		{
//		ft_printf("lala\n");
			if (i == 0)
				ft_printf("%s", paths[j]->path[i]->name);
			else
				ft_printf("--> %s", paths[j]->path[i]->name);
		}
		ft_printf("\n");
	}
}

int		find_paths(t_farm *farm, t_room *start, t_path **paths, int *checked, int *j)
{
	int	i = -1;
	if (!paths[*j])
	{
		paths[*j] = (t_path*)ft_memalloc(sizeof(t_path));
		paths[*j]->path = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->quantity + 1));
		paths[*j]->depth = -1;
	}
	checked[start->index] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;

	while (start->edges[++i])
	{
		ft_printf("start - %s edge - %s\n", start->name, start->edges[i]->name);
		if (start->edges[i]->index == farm->e_index)
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			//	paths[*j]->found = 1;
			checked[start->index] = 0;
			return (1);
		}
		if (!(checked[start->edges[i]->index]))
		{

			if (find_paths(farm, start->edges[i], paths, checked, j))
			{
				(*j)++;
				paths[*j] = (t_path*)ft_memalloc(sizeof(t_path));
				paths[*j]->path = (t_room**)ft_memalloc(sizeof(t_room*)
														* (farm->quantity+1));
				paths[*j]->depth = paths[*j - 1]->depth - 2;
				paths[*j]->path = ft_memcpy(paths[*j]->path,
						paths[*j - 1]->path,
						sizeof(paths[*j - 1]->path) * paths[*j - 1]->depth);
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[start->edges[i]->index] = 0;
			}

		}
	}


	return (0);
}

t_path	**get_paths(t_farm *farm)
{
	t_path	**paths;
	int 	*checked;
	int 	ways = 10;
	int 	j = 0;

	checked = (int*)ft_memalloc(sizeof(int) * (farm->quantity + 1));
	paths = (t_path**)ft_memalloc(sizeof(t_path*) * (ways + 1));

	find_paths(farm, farm->rooms[farm->s_index], paths, checked, &j);
	print_paths(paths);
//	int i = -1;
//	while (++i < farm->quantity)
//		ft_printf("%d ", checked[i]);


	free(checked);
	return (paths);
}

int		main()
{
	t_farm	*farm;
	t_room	**rooms;
	t_path	**paths;

	rooms = get_rooms();
	farm = make_farm(rooms);
	print_farm(farm);
	paths = get_paths(farm);
	system("leaks -q lem-in > leaks.txt");
	return (0);
}
