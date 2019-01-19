/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:34:06 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 14:34:08 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char q;
	char *last;

	q = c;
	last = NULL;
	while (*s)
	{
		if (*s == q)
			last = (char*)s;
		s++;
	}
	if (*s == q)
		return ((char*)s);
	return (last);
}
