/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:33:01 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:33:03 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_s(t_flags *flags, va_list *ap)
{
	int 	i;
	int		len;
	char	*str;

	i = 0;
	if (!(str = va_arg(*ap, char*)))
	{
		ft_putstr("(null)");
		return (6);
	}

	len = ft_strlen(str);

	if (flags->precision && flags->precision < len)
		len = flags->precision;

	if (flags->width > len)
	{
		if (flags->left_align)
		{
			while (i < len)
				ft_putchar(str[i++]);
			while (flags->width > len++)
				ft_putchar(' ');
		}
		else
		{
			while (flags->width > len + i++)
				ft_putchar(' ');
			i = 0;
			while (i < len)
				ft_putchar(str[i++]);
		}
		len = flags->width;
	}
	else
		while (i < len)
			ft_putchar(str[i++]);

	return (len);
}
