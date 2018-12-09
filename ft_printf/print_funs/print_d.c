/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:30:22 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:30:27 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_d(t_flags *flags, va_list *ap)
{
	int len;
	char *str;

	if (flags->length == 0)
		str = ft_itoa(va_arg(*ap, int));
	else if (flags->length == 1)
		str = ft_itoa((char) va_arg(*ap, int));
	else if (flags->length == 2)
		str = ft_itoa((short) va_arg(*ap, int));
	else if (flags->length == 3)
		str = ft_itoa_long(va_arg(*ap, long long));
	else
		str = ft_itoa_long(va_arg(*ap, long));

	len = ft_strlen(str);

	if (flags->precision > len)
		len = add_prefix(&str, '0', flags->precision - len);

	if ((flags->add_plus && str[0] != '-') || flags->space)
		len++;

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
		else
			len = add_prefix(&str, ' ', flags->width - len);
	}
	if (flags->add_plus && str[0] != '-')
		len = add_prefix(&str, '+', 1);
	else if (flags->space)
		len = add_prefix(&str, ' ', 1);



	ft_putstr(str);
	return (len);
}
//	printf("d\n");
/*	printf("(left_align = %d)\n", flags->left_align);
	printf("(add_plus = %d)\n", flags->add_plus);
	printf("(space = %d)\n", flags->space);
	printf("(zero = %d)\n", flags->zero);
	printf("(hash = %d)\n", flags->hash);
	printf("(width = %d)\n", flags->width);
	printf("(precision = %d)\n", flags->precision);
	printf("(length = %d)\n", flags->length); */

