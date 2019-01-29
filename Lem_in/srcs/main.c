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
	fd = open("tests/test.txt", O_RDONLY);
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
			farm->s_index = ft_itoa(i);
		else if (farm->rooms[i]->status == 2)
			farm->e_index = ft_itoa(i);
	return (farm);
}

void	print_farm(t_farm *farm)
{
	int i = -1;
	int j;

	ft_printf("Number of rooms - %d\n", farm->quantity);
	ft_printf("Start index - %s\n", farm->s_index);
	ft_printf("End index - %s\n", farm->e_index);
	while (farm->rooms[++i])
	{
		j = -1;
		ft_printf("%-3s ", farm->rooms[i]->index);
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
		if (!paths[j]->invalid)
		{
			ft_printf("Depth %d\n", paths[j]->depth);
//			ft_printf("Invalid? %d\n", paths[j]->invalid);
			ft_printf("Path: ");
			while (++i <= paths[j]->depth)
			{
//		ft_printf("lala\n");
				if (i == 0)
					ft_printf("%s", paths[j]->path[i]->index);
				else
					ft_printf("--> %s", paths[j]->path[i]->index);
			}
			ft_printf("\n");
		}
	}
}

// Function that finds broken needle in a haystack (add to libft?)

int		ft_strbrstr(t_room **haystack, t_room **needle)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (haystack[++i])
	{
		while (haystack[i + j] && ft_strequ(haystack[i + j]->index, needle[j]->index))
			j++;
		if (!needle[j])
			return (1);
	}
	i = -1;
	j = 0;
	while (needle[++i])
	{
		while (needle[i + j] && ft_strequ(needle[i + j]->index, haystack[j]->index))
			j++;
		if (!haystack[j])
			return (1);
	}
	return (0);
}

// ^ function that finds broken needle in a haystack (add to libft?)

int		find_paths(t_farm *farm, t_room *start, t_path **paths, int *checked, int *j)
{
	int	i = -1;
	checked[ft_atoi(start->index)] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;

	while (start->edges[++i])
	{
		if (ft_strequ(start->edges[i]->index, farm->e_index))
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			checked[ft_atoi(start->index)] = 0;
			return (1);
		}
		if (!(checked[ft_atoi(start->edges[i]->index)]))
		{
			if (find_paths(farm, start->edges[i], paths, checked, j))
			{
				(*j)++;
				paths[*j] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
				paths[*j]->path = (t_room**)ft_memalloc(sizeof(t_room*)
														* (farm->quantity * 2 + 1));
				paths[*j]->depth = paths[*j - 1]->depth - 2;
				paths[*j]->path = ft_memcpy(paths[*j]->path,
						paths[*j - 1]->path,
						sizeof(paths[*j - 1]->path) * (paths[*j - 1]->depth - 1));
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[ft_atoi(start->edges[i]->index)] = 0;
			}
		}
	}
	return (0);
}

void	check_valid(t_path **paths)
{
	int	i = -1;
	int	j;

	while (paths[++i])
	{
		if (!paths[i]->invalid)
		{
			j = 0;
			while (paths[i + ++j])
			{
				if (ft_strbrstr(paths[i]->path, paths[i + j]->path) && !paths[i + j]->invalid)
				{
					if (paths[i]->depth > paths[i + j]->depth)
						paths[i]->invalid = 1;
					else
						paths[i + j]->invalid = 1;
				}
			}
		}
	}
}

t_path	**get_paths(t_farm *farm)
{
	t_path	**paths;
	int 	*checked;
	int 	j = 0;

	checked = (int*)ft_memalloc(sizeof(int) * (farm->quantity + 1));
	paths = (t_path**)ft_memalloc(sizeof(t_path*) * (farm->quantity / 2 * (farm->quantity + 1)));
	paths[j] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
	paths[j]->path = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->quantity + 1));
	paths[j]->depth = -1;
	find_paths(farm, farm->rooms[ft_atoi(farm->s_index)], paths, checked, &j);
	ft_memdel((void**)&paths[j]->path);
	ft_memdel((void**)&paths[j]);

//	while (++i < farm->quantity)
//		ft_printf("%d ", checked[i]);


	check_valid(paths);


	free(checked);
	return (paths);
}

/*void	lem_in(t_farm *farm, t_path **paths)
{
	int 	ant_n = 0;
	int 	best_path = 0;
	int 	dst = 0;
	int 	best_dst = 0;
	int 	i;

	while (farm->rooms[ft_atoi(farm->s_index)]->ants > ant_n++)
	{
		i = -1;
		while (paths[++i])
		{
			if ((i == 0) || (dst = find_dist(paths[i])) <= best_dst)
			{
				best_dst = dst;
				best_path = i;
			}
		}
		i = 0;
		while (++i < paths[best_path]->depth])
		{
			paths[best_path]->path[i]
		}
	}
}*/

int		main()
{
	t_farm	*farm;
	t_room	**rooms;
	t_path	**paths;

	rooms = get_rooms();
	farm = make_farm(rooms);
	print_farm(farm);
	paths = get_paths(farm);
	print_paths(paths);
//	lem_in(farm, paths);
	system("leaks -q lem-in > leaks.txt");
	return (0);
}
