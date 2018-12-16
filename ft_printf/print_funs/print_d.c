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

static void	get_local_string(char **str, t_flags *flags, va_list *ap, int *len)
{
	if (flags->id == 'D')
		*str = ft_itoa_long(va_arg(*ap, long), 10);
	else if (flags->length == 0)
		*str = ft_itoa_long(va_arg(*ap, int), 10);
	else if (flags->length == 1)
		*str = ft_itoa_long((char)va_arg(*ap, int), 10);
	else if (flags->length == 2)
		*str = ft_itoa_long((short)va_arg(*ap, int), 10);
	else if (flags->length == 3)
		*str = ft_itoa_long(va_arg(*ap, long long), 10);
	else
		*str = ft_itoa_long(va_arg(*ap, long), 10);
	*len = ft_strlen(*str);
}

int			print_d(t_flags *flags, va_list *ap)
{
	int		len;
	int		neg;
	char	*str;

	get_local_string(&str, flags, ap, &len);
	neg = (*str == '-') ? 1 : 0;
	fix_precision(&len, flags, &str, neg);
	if ((flags->add_plus || flags->space) && !neg)
		len++;
	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
	}
	if (flags->add_plus && !neg)
		len = add_prefix(&str, '+', 1);
	else if (flags->space && !neg)
		len = add_prefix(&str, ' ', 1);
	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);
	ft_putstr(str);
	free(str);
	return (len);
}
