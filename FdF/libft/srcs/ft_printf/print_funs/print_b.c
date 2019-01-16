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

#include "../../../includes/ft_printf.h"

int		print_b(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	get_un_string(&str, flags, ap, 2);
	len = ft_strlen(str);
	fix_precision(&len, flags, &str, 0);
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
