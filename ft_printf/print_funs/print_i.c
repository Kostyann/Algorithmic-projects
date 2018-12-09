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
	(void)flags;
	char *str;

	printf("o\n");
	str = ft_itoa(va_arg(*ap, int));
	ft_putstr(str);
	return (ft_strlen(str));

//	printf("(len = %d)\n", len);


}
