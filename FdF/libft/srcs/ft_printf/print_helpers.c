/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:36:44 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/16 13:36:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void			fix_precision(int *len, t_flags *flags, char **str, int neg)
{
	if (flags->precision > *len - neg)
		*len = add_prefix(str, '0', flags->precision - *len + neg);
	else if (flags->precision == -1 && **str == '0' &&
			(!flags->hash || (flags->id != 'o' && flags->id != 'O')))
	{
		ft_strdel(str);
		*len = 0;
	}
}

void			get_un_string(char **str, t_flags *flags, va_list *ap,
								size_t base)
{
	int	i;

	if (flags->id == 'U' || flags->id == 'O')
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long), base);
	else if (flags->length == 0)
		*str = ft_itoa_ulong(va_arg(*ap, unsigned int), base);
	else if (flags->length == 1)
		*str = ft_itoa_ulong((unsigned char)va_arg(*ap, unsigned int), base);
	else if (flags->length == 2)
		*str = ft_itoa_ulong((unsigned short)va_arg(*ap, unsigned int), base);
	else if (flags->length == 3)
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long long), base);
	else
		*str = ft_itoa_ulong(va_arg(*ap, unsigned long), base);
	if (flags->id == 'X')
	{
		i = -1;
		while ((*str)[++i])
			if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
				(*str)[i] = (*str)[i] - 32;
	}
}

static float	pow_ten(int power)
{
	float	res;

	res = 1.0;
	while (power-- > 0)
		res = res * 10.0;
	return (res);
}

static void		fix_frecision(int precision, unsigned long long hard,
								long double f, char **ret)
{
	char *temp;

	while (precision-- > 0)
	{
		f = (f - hard) * 10.0;
		hard = (unsigned long long)(float)f;
		if ((f - hard) * pow_ten(precision + 1) > pow_ten(precision + 1) - 5)
		{
			hard = (hard + 1) * pow_ten(precision);
			precision = 0;
		}
		temp = ft_itoa_ulong(hard, 10);
		*ret = ft_strcat(*ret, temp);
		free(temp);
	}
}

char			*btof(long double f, int precision, int hash)
{
	unsigned long long	hard;
	char				*ret;
	char				*temp;

	ret = ft_strnew(32);
	if (f < 0.0)
	{
		ret[0] = '-';
		f = -f;
	}
	hard = (unsigned long long)f;
	if (precision == -1 && (f - hard) * 10 > 5)
		hard++;
	temp = ft_itoa_ulong(hard, 10);
	ret = ft_strcat(ret, temp);
	free(temp);
	if (precision != -1 || hash)
		ret = ft_strcat(ret, ".");
	precision = (precision == 0) ? 6 : precision;
	fix_frecision(precision, hard, f, &ret);
	return (ret);
}
