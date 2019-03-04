/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:01:23 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/02/06 17:01:25 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
**Deep-first search (DFS)
*/

int		path_exists(t_farm *farm, t_room *start, int *checked)
{
	int	i;

	i = -1;
	checked[ft_atoi(start->index)] = 1;
	if (start->edges)
	{
		while (start->edges[++i])
			if (ft_strequ(start->edges[i]->index, farm->e_index))
				return (1);
		i = -1;
		while (start->edges[++i])
			if (!(checked[ft_atoi(start->edges[i]->index)]))
				if (path_exists(farm, start->edges[i], checked))
					return (1);
	}
	return (0);
}
