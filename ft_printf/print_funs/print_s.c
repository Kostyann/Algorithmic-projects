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
	int 	f_temp;
	int		len;
	char 	*temp;
	char	*str;

	i = 0;
	f_temp = 0;
	if (!(temp = va_arg(*ap, char*)) && flags->precision != -1)
	{
		temp = ft_strdup("(null)");
		f_temp = 1;
	}

	len = ft_strlen(temp);

	if (flags->precision == -1)
	{
		str = ft_strnew(0);
		len = 0;
	}
	else if (flags->precision && flags->precision < len)
	{
		str = ft_strndup(temp, flags->precision);
		len = flags->precision;
	}
	else
		str = ft_strdup(temp);

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (flags->precision <= 0 && flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
		else
			len = add_prefix(&str, ' ', flags->width - len);
		len = flags->width;
	}

	ft_putnstr(str, len);
	free(str);
	if (f_temp)
		free(temp);
	return (len);
}
