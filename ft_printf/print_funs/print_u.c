/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:30:52 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:30:54 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"

int    print_u(t_flags *flags, va_list *ap)
{
	(void)flags;
	char *str;

	printf("u\n");
	str = ft_itoa(va_arg(*ap, int));
	ft_putstr(str);
	return (ft_strlen(str));
}
