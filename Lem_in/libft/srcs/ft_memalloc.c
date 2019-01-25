/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:11:24 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/25 11:11:25 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*ch;
	size_t	i;

	i = 0;
	if ((mem = malloc(size)))
	{
		ch = (char *)mem;
		while (i < size)
		{
			ch[i] = 0;
			i++;
		}
		mem = (void *)ch;
		return (mem);
	}
	else
		return (NULL);
}
