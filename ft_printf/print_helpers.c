/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:36:44 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/16 13:36:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/print_helpers.h"

void	fix_precision(int *len, t_flags *flags, char **str, int neg)
{
	if (flags->precision > *len - neg)
		*len = add_prefix(str, '0', flags->precision - *len + neg);
	else if (flags->precision == -1 && **str == '0' &&
				(!flags->hash || (flags->id != 'o' && flags->id != 'O')))
	{
		ft_strdel(str);
		*len = 0;
	}
}

void	get_un_string(char **str, t_flags *flags, va_list *ap, size_t base)
{
	int	i;

	if (flags->id == 'U' || flags->id == 'O')
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long), base);
	else if (flags->length == 0)
		*str = ft_itoa_ulong(va_arg(*ap, unsigned int), base);
	else if (flags->length == 1)
		*str = ft_itoa_ulong((unsigned char)va_arg(*ap, unsigned int), base);
	else if (flags->length == 2)
		*str = ft_itoa_ulong((unsigned short)va_arg(*ap, unsigned int), base);
	else if (flags->length == 3)
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long long), base);
	else
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long), base);
	if (flags->id == 'X')
	{
		i = -1;
		while ((*str)[++i])
			if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
				(*str)[i] = (*str)[i] - 32;
	}
}
