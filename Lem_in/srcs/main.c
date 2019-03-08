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
	int i;
	int j;

	i = 0;
	j = 0;
	dist = path->depth;
	while (++i < path->depth)
		if (path->path[i]->arrivals)
			while (path->path[i]->arrivals[j + i - 1])
				j++;
	dist += j;
	return (dist);
}

int		best_path(t_path **paths)
{
	int i;
	int best;

	i = -1;
	best = -1;
	while (paths[++i])
		if ((!paths[i]->invalid) && ((best == -1) || (find_dist(paths[i]))
			<= (find_dist(paths[best]))))
			best = i;
	return (best);
}

void	lem_in(t_farm *farm, t_path **paths, int ant_n)
{
	int	best;
	int	i;
	int	j;

	while (farm->ants > ant_n++ && (i = 0) == 0)
	{
		best = best_path(paths);
		j = 0;
		while (++i <= paths[best]->depth)
		{
			if (!paths[best]->path[i]->arrivals)
				paths[best]->path[i]->arrivals = (int*)ft_memalloc(sizeof(int)
						* (farm->rooms_n + farm->ants));
			if (!farm->solution[j + i - 1])
				farm->solution[j + i - 1] = (char**)ft_memalloc(sizeof(char*)
						* (farm->ants + 1));
			if (i < paths[best]->depth)
				while (paths[best]->path[i]->arrivals[j + i - 1])
					j++;
			paths[best]->path[i]->arrivals[j + i - 1] = ant_n;
			farm->solution[j + i - 1][ant_n - 1] = paths[best]->path[i]->name;
		}
	}
}

int		main(void)
{
	t_farm	*farm;
	t_path	**paths;

	farm = make_farm();
	paths = get_paths(farm);
	farm->solution = (char***)ft_memalloc(sizeof(char**)
			* (farm->rooms_n + farm->ants));
	lem_in(farm, paths, 0);
	print_farm(farm);
	print_solution(farm);
	return (0);
}
