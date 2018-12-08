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

int    print_d(t_flags *flags, va_list *ap)
{
	(void)flags;
	char *str;

//	printf("d\n");
/*	printf("(left_align = %d)\n", flags->left_align);
	printf("(add_plus = %d)\n", flags->add_plus);
	printf("(space = %d)\n", flags->space);
	printf("(zero = %d)\n", flags->zero);
	printf("(hash = %d)\n", flags->hash);
	printf("(width = %d)\n", flags->width);
	printf("(precision = %d)\n", flags->precision);
	printf("(length = %d)\n", flags->length); */
	str = ft_itoa(va_arg(*ap, int));
	ft_putstr(str);
	return (ft_strlen(str));
}
