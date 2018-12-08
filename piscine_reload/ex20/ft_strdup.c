/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:51:35 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/24 14:08:05 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = 0;
	while (src[i])
		i++;
	if ((res = (char*)malloc(i * sizeof(char) + 1)))
	{
		while (src[j])
		{
			res[j] = src[j];
			j++;
		}
		res[j] = '\0';
	}
	return (res);
}
