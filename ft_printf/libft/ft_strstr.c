/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:11:52 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 13:11:54 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!needle[i])
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
