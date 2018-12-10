/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:32:48 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:32:50 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_c(t_flags *flags, va_list *ap)
{
	int		len;
	char	c;

	len = 1;
	c = va_arg(*ap, int);

	if (flags->width)
	{
		if (flags->left_align)
			ft_putchar(c);
		while (flags->width > len++)
			ft_putchar(' ');
		len--;
		if (!flags->left_align)
			ft_putchar(c);
	}
	else
		ft_putchar(c);

	return (len);
}
