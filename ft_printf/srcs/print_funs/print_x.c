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

#include "../../libft/includes/print_funs.h"

int	print_x(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	get_un_string(&str, flags, ap, 16);
	len = ft_strlen(str);
	fix_precision(&len, flags, &str, 0);
	if (flags->width > (len + (flags->hash * 2)))
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len - (flags->hash * 2));
		else if (!flags->precision && flags->zero)
			len = add_prefix(&str, '0', flags->width - len - (flags->hash * 2));
	}
	if (flags->hash && len > 1)
	{
		len = (flags->id == 'x') ? add_prefix(&str, 'x', 1) :
				add_prefix(&str, 'X', 1);
		len = add_prefix(&str, '0', 1);
	}
	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);
	ft_putstr(str);
	free(str);
	return (len);
}
