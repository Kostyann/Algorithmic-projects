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

#define MAX(a, b) a > b ? a : b

int		print_i(t_flags *flags, va_list *ap)
{
	int		len;
	int		neg;
	char	*str;



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
	neg = (*str == '-') ? 1 : 0;

	int sign = flags->add_plus + flags->space - neg;
	len = MAX(flags->width, (MAX(flags->precision, len) + sign));

//	printf("(len = %d)\n", len);


	ft_putstr(str);
	return (len);
}
