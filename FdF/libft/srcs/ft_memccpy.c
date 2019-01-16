/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:18:39 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/26 10:18:42 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;
	unsigned char	cc;

	i = 0;
	dest = (unsigned char*)dst;
	sour = (unsigned char*)src;
	cc = (unsigned char)c;
	while ((i < n))
	{
		dest[i] = sour[i];
		if (sour[i] == cc)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
