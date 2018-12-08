/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:41:58 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:42:00 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s)
	{
		if ((str = ft_strnew(len)))
		{
			while (s[start] && len)
			{
				str[i] = s[start + i];
				i++;
				len--;
			}
		}
	}
	return (str);
}
