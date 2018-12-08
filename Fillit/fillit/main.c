/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:49:15 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/10 11:49:17 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		quant;
	int		i;
	char	**field;

	if (ac == 2)
	{
		quant = read_tet(av[1]);
		if (quant)
		{
			i = 0;
			save_tet(quant);
			field = create_field(ft_sqrt(quant * 4));
			while (!place_tets(&field, quant, quant))
			{
				free(field);
				field = create_field(ft_sqrt(quant * 4) + ++i);
			}
			print_field(field);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage: ./fillit source_file\n", 28);
	return (0);
}
