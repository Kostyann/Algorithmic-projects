/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:41:25 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:41:27 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1 || *s2)
		{
			if ((unsigned char)*s1 != (unsigned char)*s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}
