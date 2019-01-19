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

#include "../../../include/ft_printf.h"

static void	fix_str_prec(int *len, char **str, char **temp, int precision)
{
	if (precision == -1)
	{
		*str = ft_strnew(0);
		*len = 0;
	}
	else if (precision && precision < *len)
	{
		*str = ft_strndup(*temp, precision);
		*len = precision;
	}
	else
		*str = ft_strdup(*temp);
}

static void	fix_width(int *len, char **str, t_flags *flags)
{
	if (flags->width > *len)
	{
		if (flags->left_align)
			add_suffix(str, ' ', flags->width - *len);
		else if (flags->precision <= 0 && flags->zero)
			add_prefix(str, '0', flags->width - *len);
		else
			add_prefix(str, ' ', flags->width - *len);
		*len = flags->width;
	}
}

int			print_s(t_flags *flags, va_list *ap)
{
	int		f_temp;
	int		len;
	char	*temp;
	char	*str;

	f_temp = 0;
	if (!(temp = va_arg(*ap, char*)) && flags->precision != -1)
	{
		temp = ft_strdup("(null)");
		f_temp = 1;
	}
	len = ft_strlen(temp);
	fix_str_prec(&len, &str, &temp, flags->precision);
	fix_width(&len, &str, flags);
	ft_putnstr(str, len);
	free(str);
	if (f_temp)
		free(temp);
	return (len);
}
