/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:33:11 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:33:13 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	print_p(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	str = ft_itoa_ulong(va_arg(*ap, unsigned long long), 16);
	len = ft_strlen(str);
	if (len == 1 && flags->precision == -1)
		ft_strdel(&str);
	if (flags->precision > len)
		add_prefix(&str, '0', flags->precision - len);
	add_prefix(&str, 'x', 1);
	add_prefix(&str, '0', 1);
	len = ft_strlen(str);
	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
		else
			len = add_prefix(&str, ' ', flags->width - len);
	}
	ft_putstr(str);
	free(str);
	return (len);
}
