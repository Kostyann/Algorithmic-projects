/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:30:18 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 19:30:21 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/resolvers.h"

static void	resolve_width(t_flags *flags, const char **format, va_list *ap)
{
	char *str;

	if (**format && **format >= '0' && **format <= '9')
	{
		flags->width = ft_atoi(*format);
		str = ft_itoa(flags->width);
		(*format) += ft_strlen(str) - 1;
		free(str);
	}
	if (**format && **format == '*')
	{
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
		{
			flags->left_align = 1;
			flags->width = -flags->width;
		}
	}
}

static void	resolve_precision(t_flags *flags, const char **format, va_list *ap)
{
	char	*str;

	if (**format && **format == '.' && ft_atoi(*format + 1) > 0)
	{
		flags->precision = ft_atoi(++(*format));
		str = ft_itoa(flags->precision);
		(*format) += ft_strlen(str) - 1;
		free(str);
	}
	if (**format && **format == '.' && *(*format + 1) == '*')
	{
		flags->precision = va_arg(*ap, int);
		if (flags->precision < 0)
			flags->precision = 0;
		else if (flags->precision == 0)
			flags->precision = -1;
		(*format)++;
	}
	else if (**format && **format == '.' && !ft_atoi(*format + 1))
		flags->precision = -1;
}

static void	resolve_length(t_flags *flags, const char **format)
{
	if (*format && **format == 'h' && *(*format + 1) == 'h')
	{
		flags->length = 1;
		(*format) += 2;
	}
	else if (*format && **format == 'h')
	{
		flags->length = 2;
		(*format)++;
	}
	else if (*format && **format == 'l' && *(*format + 1) == 'l')
	{
		flags->length = 3;
		(*format) += 2;
	}
	else if (*format && **format == 'l')
	{
		flags->length = 4;
		(*format)++;
	}
	else if (*format && **format == 'L')
	{
		flags->length = 5;
		(*format)++;
	}
}

void		resolve_flags(t_flags *flags, const char **format, va_list *ap)
{
	while (**format && (**format == '-' || **format == '+' || **format == ' '
			|| **format == '0' || **format == '#' || **format == '.' ||
			**format == '*' || (**format >= '0' && **format <= '9')))
	{
		if (**format == '-')
			flags->left_align = 1;
		else if (**format == '+')
			flags->add_plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '.')
			resolve_precision(flags, format, ap);
		else
			resolve_width(flags, format, ap);
		(*format)++;
	}
	resolve_length(flags, format);
	if (flags->left_align)
		flags->zero = 0;
	if (flags->add_plus)
		flags->space = 0;
}
