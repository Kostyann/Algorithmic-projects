/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:38:13 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/26 11:38:16 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*c_dst;
	char	*c_src;

	i = -1;
	c_dst = (char*)dst;
	c_src = (char*)src;
	if (dst > src)
		while ((int)--len >= 0)
			c_dst[len] = c_src[len];
	else
		while (++i < len)
			c_dst[i] = c_src[i];
	return (dst);
}
