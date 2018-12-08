/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:55:41 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/30 13:55:42 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, unsigned int n)
{
	unsigned int	i;
	int				j;
	char			*res;

	i = 0;
	j = 0;
	res = 0;
	while (src[i])
		i++;
	if (n > i)
		n = i;
	if ((res = (char*)malloc(n * sizeof(char) + 1)))
	{
		while (src[j] && n > 0)
		{
			res[j] = src[j];
			j++;
			n--;
		}
		res[j] = '\0';
	}
	else
		return (NULL);
	return (res);
}
