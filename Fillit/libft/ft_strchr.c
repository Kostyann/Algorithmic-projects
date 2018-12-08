/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:23:47 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 14:23:48 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char q;

	q = c;
	while (*s)
	{
		if (*s == q)
			return ((char*)s);
		s++;
	}
	if (*s == q)
		return ((char*)s);
	return (NULL);
}
