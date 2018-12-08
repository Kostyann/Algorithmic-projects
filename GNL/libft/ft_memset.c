/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:59:15 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 17:59:17 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*d;
	unsigned char	q;

	i = 0;
	d = (char*)b;
	q = (unsigned char)c;
	while (i < len)
	{
		d[i] = q;
		i++;
	}
	return ((void*)d);
}
