/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:02:23 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/24 13:02:29 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_digits(int c)
{
	int i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}
