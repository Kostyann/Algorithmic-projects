/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:33:24 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/24 10:07:09 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int rng;
	int i;

	rng = max - min;
	i = 0;
	if (min >= max)
		return (0);
	range = (int*)malloc((rng + 1) * sizeof(int));
	while (rng >= i)
	{
		range[i] = 0;
		i++;
	}
	i = 0;
	while (rng > i)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
