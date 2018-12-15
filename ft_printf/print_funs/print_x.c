/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:31:08 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:31:24 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_x(t_flags *flags, va_list *ap)
{
	int		i;
	int		len;
	char	*str;

	if (flags->length == 0)
		str = ft_itoa_ulong(va_arg(*ap, unsigned int), 16);
	else if (flags->length == 1)
		str = ft_itoa_ulong((unsigned char)va_arg(*ap, unsigned int), 16);
	else if (flags->length == 2)
		str = ft_itoa_ulong((unsigned short)va_arg(*ap, unsigned int), 16);
	else if (flags->length == 3)
		str = ft_itoa_ulong(va_arg(*ap, unsigned long long), 16);
	else
		str = ft_itoa_ulong(va_arg(*ap, unsigned long), 16);

	if (flags->id == 'X')
	{
		i = -1;
		while (str[++i])
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
	}

	len = ft_strlen(str);

	if (flags->precision > len)
		len = add_prefix(&str, '0', flags->precision - len);
	else if (flags->precision == -1 && *str == '0')
	{
		ft_strdel(&str);
		len = 0;
	}

	if (flags->width > (len + (flags->hash * 2)))
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len - (flags->hash * 2));
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len - (flags->hash * 2));
	}

	if (flags->hash && ft_atoi(str))
	{
		len = (flags->id == 'x') ? add_prefix(&str, 'x', 1) : add_prefix(&str, 'X', 1);
		len = add_prefix(&str, '0', 1);
	}

	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);

	ft_putstr(str);
	free(str);
	return (len);
}

