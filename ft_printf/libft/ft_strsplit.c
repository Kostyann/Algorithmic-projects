/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:42:51 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:42:53 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static int	word_num(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word_l;
	int		word_n;
	char	**res;

	i = -1;
	word_l = 0;
	if (!s || !(res = (char**)malloc((word_num(s, c) + 1) * sizeof(*res))))
		return (NULL);
	word_n = word_num(s, c);
	while (++i < word_n)
	{
		while (*s && *s == c)
			s++;
		word_l = word_len(s, c);
		if (*s && (res[i] = ft_strnew(word_l)))
		{
			j = 0;
			while (j < word_l)
				res[i][j++] = *(s++);
		}
	}
	res[i] = NULL;
	return (res);
}
