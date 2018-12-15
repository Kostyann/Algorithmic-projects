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
	char 	s;
	(void)	ap;

	len = 1;
	s = flags->zero ? '0' : ' ';

	if (flags->width)
	{
		if (flags->left_align)
			ft_putchar(flags->id);
		while (flags->width > len++)
			ft_putchar(s);
		len--;
		if (!flags->left_align)
			ft_putchar(flags->id);
	}
	else
		ft_putchar(flags->id);

	return (len);
}
