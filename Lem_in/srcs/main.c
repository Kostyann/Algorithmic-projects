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

int		find_dist(t_path *path)
{
	int dist;
	int i = 0;
	int j = 0;

	dist = path->depth;
	while (++i < path->depth)
	{
		if (path->path[i]->arrivals)
		{
			while (path->path[i]->arrivals[j + i - 1])
				j++;
		}
	}
	dist += j;
	return (dist);
}

void	lem_in(t_farm *farm, t_path **paths)
{
	int 	ant_n = 0;
	int 	best_path = 0;
	int 	dst = 0;
	int 	best_dst = 0;
	int 	i;
	int 	j;

	farm->solution = (char***)ft_memalloc(sizeof(char**) * (farm->rooms_n + farm->ants));
	while (farm->ants > ant_n++)
	{
		i = -1;
		best_path = 0;
		dst = 0;
		best_dst = 0;
//		ft_printf("ants_n - %d\n", ant_n);
		while (paths[++i])
		{
			if ((!paths[i]->invalid) &&
				((dst = find_dist(paths[i])) <= best_dst || (best_dst == 0)))
			{
				best_dst = dst;
				best_path = i;
			//	ft_printf("Best path - %d\n", best_path);
			}
		}
		i = 0;
		j = 0;
		while (++i <= paths[best_path]->depth)
		{
			if (!paths[best_path]->path[i]->arrivals)
				paths[best_path]->path[i]->arrivals = (int*)ft_memalloc(sizeof(int) *
						(farm->rooms_n + farm->ants));
			if (i < paths[best_path]->depth)
				while (paths[best_path]->path[i]->arrivals[j + i - 1])
					j++;
			paths[best_path]->path[i]->arrivals[j + i - 1] = ant_n;
			if (!farm->solution[j + i - 1])
				farm->solution[j + i - 1] = (char**)ft_memalloc(sizeof(char*)
						* (farm->ants + 1));
			farm->solution[j + i - 1][ant_n - 1] = paths[best_path]->path[i]->name;
		}
	}
}

int		main()
{
	t_farm	*farm;
	t_path	**paths;

	farm = make_farm();
	print_farm(farm);
	paths = get_paths(farm);
	print_paths(paths, farm);
	lem_in(farm, paths);
	print_solution(farm);
	system("leaks -q lem-in > leaks.txt");
	return (0);
}
