/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:43:20 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 18:40:04 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 1;
	len = ft_len(n);
	if (n == 0)
	{
		if ((str = ft_strnew(1)))
			str[0] = '0';
		return (str);
	}
	if (n < 0)
		neg = -1;
	if ((str = ft_strnew(len)))
	{
		if (neg == -1)
			str[0] = '-';
		while (n != 0)
		{
			str[--len] = (n % 10) * neg + '0';
			n /= 10;
		}
	}
	return (str);
}
