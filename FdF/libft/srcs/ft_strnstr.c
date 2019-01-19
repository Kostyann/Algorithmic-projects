/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:36:23 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 13:36:25 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j])
			j++;
		if (!needle[j] && i + j <= len)
			return ((char*)&haystack[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
