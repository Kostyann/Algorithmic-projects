/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:33:27 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:33:29 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"

int    print_percent(t_flags *flags, va_list *ap)
{
	int		len;
	(void)	ap;

	len = 1;

	if (flags->width)
	{
		if (flags->left_align)
			ft_putchar('%');
		while (flags->width > len++)
			ft_putchar(' ');
		len--;
		if (!flags->left_align)
			ft_putchar('%');
	}
	else
		ft_putchar('%');

	return (len);
}
