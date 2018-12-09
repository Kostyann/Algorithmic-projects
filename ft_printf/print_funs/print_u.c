/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:30:52 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:30:54 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_u(t_flags *flags, va_list *ap)
{
	int		len;
	int		neg;
	char	*str;

	if (flags->length == 0)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int));
	else if (flags->length == 1)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int));
	else if (flags->length == 2)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int));
	else if (flags->length == 3)
		str = ft_itoa_ulong(va_arg(*ap, unsigned long long));
	else
		str = ft_itoa_ulong(va_arg(*ap, unsigned long));

	len = ft_strlen(str);
	neg = (*str == '-') ? 1 : 0;

	if (flags->precision > len - neg)
		len = add_prefix(&str, '0', flags->precision - len + neg);
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
	return (len);
}
