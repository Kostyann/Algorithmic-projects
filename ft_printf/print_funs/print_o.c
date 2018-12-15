/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:30:43 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:30:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_o(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	if (flags->id == 'O')
		str = ft_itoa_ulong(va_arg(*ap, unsigned long), 8);
	else if (flags->length == 0)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int), 8);
	else if (flags->length == 1)
		str = ft_itoa_ulong((unsigned char)va_arg(*ap, unsigned int), 8);
	else if (flags->length == 2)
		str = ft_itoa_ulong((unsigned short)va_arg(*ap, unsigned int), 8);
	else if (flags->length == 3)
		str = ft_itoa_ulong(va_arg(*ap, unsigned long long), 8);
	else
		str = ft_itoa_ulong(va_arg(*ap, unsigned long), 8);

	len = ft_strlen(str);

	if (flags->precision > len)
		len = add_prefix(&str, '0', flags->precision - len);
	else if (flags->precision == -1 && *str == '0')
	{
		ft_strdel(&str);
		len = 0;
	}

	if (flags->hash && (len != 1 || *str != '0'))
		len = add_prefix(&str, '0', 1);

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
