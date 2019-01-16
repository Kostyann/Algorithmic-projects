/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:00:14 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/26 12:00:15 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	cc;

	i = 0;
	ss = (unsigned char*)s;
	cc = (unsigned char)c;
	while ((i < n))
	{
		if (ss[i] == cc)
			return ((char*)&ss[i]);
		i++;
	}
	return (NULL);
}
