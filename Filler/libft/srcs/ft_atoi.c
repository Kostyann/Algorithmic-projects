/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:14:47 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 16:14:49 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	n;

	res = 0;
	n = 1;
	if (!str)
		return (0);
	while ((*str > 7 && *str < 14) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		n = -1;
	}
	while (*str > 47 && *str < 58)
	{
		if (9223372036854775807 - res < *str - 48)
			return (n < 0 ? 0 : -1);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * n);
}
