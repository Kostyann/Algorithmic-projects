/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:49:05 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 11:49:06 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (!src[j])
			dst[i] = '\0';
		else
			dst[i] = src[j++];
		i++;
	}
	return (dst);
}
