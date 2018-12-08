/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:42:29 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:42:30 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		j;
	int		len;
	char	*str;

	if (s)
	{
		j = 0;
		while (*s == '\t' || *s == '\n' || *s == ' ')
			s++;
		len = ft_strlen(s);
		if (len < 1)
			return ((str = ft_strnew(1)));
		while (s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == ' ')
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
