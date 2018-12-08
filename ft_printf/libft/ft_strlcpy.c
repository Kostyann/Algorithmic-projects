/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:25:57 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/30 14:25:58 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t j;
	size_t k;

	j = 0;
	k = 0;
	if (src)
	{
		while (src[j])
			j++;
		if (dstsize > 0)
		{
			while (k < (dstsize - 1) && src[k])
			{
				dst[k] = src[k];
				k++;
			}
			dst[k] = '\0';
		}
	}
	return (j);
}
