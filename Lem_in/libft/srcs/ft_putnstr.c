/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:25:01 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/15 12:25:09 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = n < len ? n : len;
	if (s)
		write(1, s, i);
}
