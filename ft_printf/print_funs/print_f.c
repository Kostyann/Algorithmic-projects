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

static char	*ft_weird(long double f, char id)
{
	char		*str;
	long double	inf;
	long double	minus_inf;

	str = ft_strnew(9);
	inf = 1 / 0.0;
	minus_inf = -1 / 0.0;
	if (f == inf)
		return (str = (id == 'f') ?
				ft_strcat(str, "inf") : ft_strcat(str, "INF"));
	else if (f == minus_inf)
		return (str = (id == 'f') ?
				ft_strcat(str, "-inf") : ft_strcat(str, "-INF"));
	else
		return (str = (id == 'f') ?
				ft_strcat(str, "nan") : ft_strcat(str, "NAN"));
}

static void	fix_fwidth(char **str, t_flags *flags, int n)
{
	int len;

	len = ft_strlen(*str);
	if ((flags->add_plus || flags->space) && !n && **str != 'n' && **str != 'N')
		len++;
	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(str, ' ', flags->width - len);
		else if (flags->zero && **str >= '0' && **str <= '9')
			len = add_prefix(str, '0', flags->width - len);
	}
	if (flags->add_plus && !n && **str != 'n' && **str != 'N')
		len = add_prefix(str, '+', 1);
	else if (flags->space && !n && **str != 'n' && **str != 'N')
		len = add_prefix(str, ' ', 1);
	if (flags->width > len)
		len = add_prefix(str, ' ', flags->width - len);
}

int			print_f(t_flags *flags, va_list *ap)
{
	int			len;
	int			neg;
	char		*str;
	char		*dot;
	long double	f;

	if (flags->length == 5)
		f = va_arg(*ap, long double);
	else
		f = va_arg(*ap, double);
	if (flags->length != 5 && (f == 1 / 0.0 || f == -1 / 0.0 || f != f))
		str = ft_weird(f, flags->id);
	else
		str = btof(f, flags->precision, flags->hash);
	len = ft_strlen(str);
	dot = ft_strchr(str, '.');
	neg = (*str == '-') ? 1 : 0;
	if (flags->precision > FRACTION_LEN)
		len = add_suffix(&str, '0', flags->precision - FRACTION_LEN);
	else if (dot && flags->precision > 0 && flags->precision < FRACTION_LEN)
		str[dot - str + flags->precision + 1] = '\0';
	fix_fwidth(&str, flags, neg);
	ft_putstr(str);
	free(str);
	return (len);
}
