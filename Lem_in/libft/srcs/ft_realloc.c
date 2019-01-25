/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:07:32 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/23 17:07:34 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*mem;

	if (ptr)
	{
		if ((mem = ft_memalloc(size)))
		{
			mem = ft_memmove(mem, ptr, size);
			ft_memdel(&ptr);
			return (mem);
		}
		else
			return (ptr);
	}
	else if ((mem = ft_memalloc(size)))
		return (mem);
	return (0);
}
