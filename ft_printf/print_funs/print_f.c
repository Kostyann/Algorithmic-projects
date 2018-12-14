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

static int	power_ten(int power)
{
	int	res;

	res = 1;
	while (power-- > 0)
		res = res * 10;
	return (res);
}

static char	*ft_weird(long double f, char id)
{
	char *str;
	long double inf = 1/0.0;
	long double minus_inf = -1/0.0;

	str = ft_strnew(9);
	if (f == inf)
		return (str = (id == 'f') ? ft_strcat(str, "inf") : ft_strcat(str, "INF"));
	else if (f == minus_inf)
		return (str = (id == 'f') ? ft_strcat(str, "-inf") : ft_strcat(str, "-INF"));
	else
		return (str = (id == 'f') ? ft_strcat(str, "nan") : ft_strcat(str, "NAN"));
}

char		*btoa(long double f, int precision, int hash)
{
	unsigned long long hard;
	long double minus_zero = -1 / (1 / 0.0);
	char *ret;
	char *temp;

	ret = ft_strnew(3222);
//	printf("(minus_zero = %Lf)\n", minus_zero);
//	printf("(f = %Lf)\n", f);
	if (f < 0 || f == minus_zero)
	{
//		printf("Kaka\n");
		ret[0] = '-';
		f = -f;
	}

	hard = (unsigned long long)f;
	temp = ft_itoa_ulong(hard, 10);
	ret = ft_strcat(ret, temp);
	free(temp);
	if (precision != -1 || hash)
		ret = ft_strcat(ret, ".");
	precision = (precision == 0) ? 6 : precision;
	while (precision-- > 0)
	{
//		printf("(precision = %d)\n", precision);
//		printf("(f1 = %Lf)\n", f);
//		printf("(hard1 = %llu)\n", hard);
		f = (f - hard) * 10.0;
//		printf("(f2 = %Lf)\n", f);


		hard = (unsigned long long)(float)f;
//		printf("(hard1 = %llu)\n", hard);
		if ((f - hard) * power_ten(precision + 1) > power_ten(precision + 1) - 5)
		{
			hard = (hard + 1) * power_ten(precision);
			precision = 0;
		}
		temp = ft_itoa_ulong(hard, 10);
		ret = ft_strcat(ret, temp);
		free(temp);
//		printf("________________\n");
	}
	return (ret);
}

int			print_f(t_flags *flags, va_list *ap)
{
	int		len;
	int		neg;
	char	*str;
	char 	*dot;
	long double	f;

	if (flags->length == 5)
	{
		f = va_arg(*ap, long double);
		str = btoa(f, flags->precision, flags->hash);
	}
	else
	{
		f = va_arg(*ap, double);
		if (f == 1 / 0.0 || f == -1 / 0.0 || f != f)
			str = ft_weird(f, flags->id);
		else
			str = btoa(f, flags->precision, flags->hash);
	}

	len = ft_strlen(str);
	dot = ft_strchr(str, '.');
	neg = (*str == '-') ? 1 : 0;

	if (flags->precision > len - (dot - str) - 1)
		len = add_suffix(&str, '0', flags->precision - len + (dot - str) + 1);
	else if (dot && flags->precision > 0 && flags->precision < len - (dot - str) - 1)
		str[dot - str + flags->precision + 1] = '\0';

	len = ft_strlen(str);

	if ((flags->add_plus || flags->space) && !neg && *str != 'n' && *str != 'N')
		len++;

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else if (flags->zero && *str >= '0' && *str <= '9')
			len = add_prefix(&str, '0', flags->width - len);
	}
	if (flags->add_plus && !neg && *str != 'n' && *str != 'N')
		len = add_prefix(&str, '+', 1);
	else if (flags->space && !neg && *str != 'n' && *str != 'N')
		len = add_prefix(&str, ' ', 1);
	if (flags->width > len)
		len = add_prefix(&str, ' ', flags->width - len);

	ft_putstr(str);
	free(str);
	return (len);
}
