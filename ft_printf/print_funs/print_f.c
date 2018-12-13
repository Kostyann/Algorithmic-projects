/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:33:21 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:33:22 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

char 	*btoa(double f, int precision, int hash)
{
	unsigned long long hard;
	char *ret;
	char *temp;

	ret = ft_strnew(32);
	if (f < 0)
	{
		ret[0] = '-';
		f = -f;
	}

	hard = (unsigned long long) f;
	temp = ft_itoa_ulong(hard, 10);
	ret = ft_strcat(ret, temp);
	free(temp);
	if (precision != -1 || hash)
		ret = ft_strcat(ret, ".");
	precision = (precision == 0) ? 6 : precision;
	while (precision-- > 0)
	{
		f = (f - hard) * 10;
		hard = (unsigned long long) f;
		if (precision == 0 && (f - hard) * 10 > 5)
			hard++;
		if (precision == 1 && (f - hard) * 100 > 95)
		{
			hard = (hard + 1) * 10;
			precision--;
		}
		temp = ft_itoa_ulong(hard, 10);
		ret = ft_strcat(ret, temp);
		free(temp);
	}
	return (ret);
}

int		print_f(t_flags *flags, va_list *ap)
{
	int		len;
	int		neg;
	char	*str;
	char 	*dot;

	double f = va_arg(*ap, double);
	str = btoa(f, flags->precision, flags->hash);

	len = ft_strlen(str);
	dot = ft_strchr(str, '.');
	neg = (*str == '-') ? 1 : 0;

	if (flags->precision > len - (dot - str) - 1)
		len = add_suffix(&str, '0', flags->precision - len + (dot - str) + 1);
	else if (flags->precision > 0 && flags->precision < len - (dot - str) - 1)
		str[dot - str + flags->precision + 1] = '\0';

	len = ft_strlen(str);

	if ((flags->add_plus || flags->space) && !neg)
		len++;

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (flags->zero)
			len = add_prefix(&str, '0', flags->width - len);
	}
	if (flags->add_plus && !neg)
		len = add_prefix(&str, '+', 1);
	else if (flags->space && !neg)
		len = add_prefix(&str, ' ', 1);
	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);

	ft_putstr(str);
	free(str);
	return (len);
}
