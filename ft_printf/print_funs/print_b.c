/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:30:36 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:30:37 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int		print_b(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	if (flags->length == 0)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int), 2);
	else if (flags->length == 1)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int), 2);
	else if (flags->length == 2)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int), 2);
	else if (flags->length == 3)
		str = ft_itoa_ulong(va_arg(*ap, unsigned long long), 2);
	else
		str = ft_itoa_ulong(va_arg(*ap, unsigned long), 2);

	len = ft_strlen(str);

	if (flags->precision > len)
		len = add_prefix(&str, '0', flags->precision - len);
	else if (flags->precision == -1 && *str == '0')
		ft_strdel(&str);

	len = ft_strlen(str);

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
	}
	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);

	ft_putstr(str);
	free(str);
	return (len);
}
