/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:11:06 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/30 16:11:10 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*void	print_farm(t_farm *farm)
{
	int i = -1;
	int j;

	ft_printf(" -----------------------------------\n");
	ft_printf("GRAPG REPRESENTATION (Adjacency list)\n -----------------------------------\n");
	ft_printf("Number of ants - %d\n", farm->ants);
	ft_printf("Number of rooms - %d\n", farm->rooms_n);
	ft_printf("Start index - %s\n", farm->s_index);
	ft_printf("End index - %s\n", farm->e_index);
	while (farm->rooms[++i])
	{
		j = -1;
		ft_printf("%-3s ", farm->rooms[i]->index);
		ft_printf("%-6s ", farm->rooms[i]->name);
		if (farm->rooms[i]->edges)
			while (farm->rooms[i]->edges[++j])
				ft_printf("->%-7s", farm->rooms[i]->edges[j]->name);
		ft_printf("\n");
	}
	ft_printf(" -----------------------------------\n");
} */

void	print_farm(t_farm *farm)
{
	int i = -1;
	while (farm->view[++i])
		ft_printf("%s\n", farm->view[i]);
	ft_printf("\n");
}

void	print_paths(t_path **paths, t_farm *farm)
{
	int	i = -1;
	int j = -1;


	ft_printf("POSSIBLE PATHS\n -----------------------------------\n");
	while (paths[++j])
	{
		i = -1;
		if (!paths[j]->invalid)
		{
			ft_printf("Depth %d\n", paths[j]->depth);
//			ft_printf("Invalid? %d\n", paths[j]->invalid);
			ft_printf("Path #%d: ", j);
			while (paths[j]->path[++i])
			{
//		ft_printf("lala\n");
				if (i == 0)
					ft_printf("%s", paths[j]->path[i]->name);
				else
					ft_printf("--> %s", paths[j]->path[i]->name);
				/*			if (paths[j]->path[i]->arrivals)
							{
								k = -1;
								ft_printf("\nArrivals[");
								while (++k < (farm->ants + farm->rooms_n))
									ft_printf("%d, ", paths[j]->path[i]->arrivals[k]);
								ft_printf("]\n");
							} */

			}
			ft_printf("\n");
		}
	}
	ft_printf(" -----------------------------------\n");
}

void	print_solution(t_farm *farm)
{
	int i = -1;
	int j;

	while (++i < (farm->rooms_n + farm->ants))
	{
		if (farm->solution[i])
		{
			j = -1;
			while (++j < farm->ants)
				if (farm->solution[i][j])
					ft_printf("L%d-%s ", j + 1, farm->solution[i][j]);

			ft_printf("\n");
		}
		//	ft_printf("\n");
	}
}
