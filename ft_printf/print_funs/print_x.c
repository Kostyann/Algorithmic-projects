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

int    print_x(t_flags *flags, va_list *ap)
{
	(void)flags;
	char *str;

	printf("x\n");
	str = ft_itoa(va_arg(*ap, int));
	ft_putstr(str);
	return (ft_strlen(str));
}

