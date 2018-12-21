/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:12:02 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/27 20:12:04 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*ch;
	size_t	i;

	i = 0;
	if ((ch = (char*)malloc(size + 1)))
	{
		while (i <= size)
		{
			ch[i] = '\0';
			i++;
		}
		ch = (void *)ch;
		return (ch);
	}
	else
		return (NULL);
}
