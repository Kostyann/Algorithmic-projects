/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:46:00 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/26 09:46:03 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sour;

	i = 0;
	dest = (char*)dst;
	sour = (char*)src;
	while ((i < n))
	{
		dest[i] = sour[i];
		i++;
	}
	return (dest);
}
