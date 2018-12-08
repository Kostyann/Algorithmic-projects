/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:57:05 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/30 13:57:06 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	int		j;
	int		len;
	char	*str;

	if (s)
	{
		j = 0;
		while (*s == c)
			s++;
		len = ft_strlen(s);
		if (len < 1)
			return ((str = ft_strnew(1)));
		while (s[len - 1] == c)
			len--;
		if ((str = ft_strnew(len)))
		{
			while (len-- > 0)
			{
				str[j] = s[j];
				j++;
			}
		}
		return (str);
	}
	return (NULL);
}
