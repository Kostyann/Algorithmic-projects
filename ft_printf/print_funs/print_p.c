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

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_p(t_flags *flags, va_list *ap)
{
	int		len;
	char	*str;

	str = ft_itoa_ulong(va_arg(*ap, unsigned long long), 16);

	len = add_prefix(&str, 'x', 1);
	len = add_prefix(&str, '0', 1);

	len = ft_strlen(str);

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else
			len = add_prefix(&str, ' ', flags->width - len);
	}

	ft_putstr(str);
	return (len);
}
