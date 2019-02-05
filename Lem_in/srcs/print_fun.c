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

void	print_farm(t_farm *farm)
{
	int i;

	i = -1;
	while (farm->view[++i])
		ft_printf("%s\n", farm->view[i]);
	ft_printf("\n");
}

void	print_solution(t_farm *farm)
{
	int i;
	int j;

	i = -1;
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
	}
}
