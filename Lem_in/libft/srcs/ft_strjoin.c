/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:42:13 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:42:14 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s1 && s2)
	{
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			while (*s1)
			{
				str[i] = *s1;
				i++;
				s1++;
			}
			while (*s2)
			{
				str[i] = *s2;
				i++;
				s2++;
			}
		}
	}
	return (str);
}
