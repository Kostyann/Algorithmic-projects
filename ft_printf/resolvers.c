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

void 	resolve_flags(t_flags *flags, const char **format)
{
	while (**format && (**format == '-' || **format == '+' || **format == ' '
						|| **format == '0' || **format == '#'))
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
		(*format)++;
	}
	if (flags->left_align)
		flags->zero = 0;
	if (flags->add_plus)
		flags->space = 0;
}

void	resolve_width(t_flags *flags, const char **format)
{
	char *str;
	if (**format && **format >= '0' && **format <= '9')
	{
		str = ft_itoa(flags->width = ft_atoi(*format));
		(*format) += ft_strlen(str);
		free(str);
	}

}

void	resolve_precision(t_flags *flags, const char **format)
{
	char	*str;

	if (**format && **format == '.' && ft_atoi(*format + 1))
	{
		str = ft_itoa(flags->precision = ft_atoi(++(*format)));
		(*format) += ft_strlen(str);
		free(str);
	}

	else if (**format && **format == '.')
	{
		flags->precision = -1;
		(*format)++;
		while (**format == '0')
			(*format)++;
	}
}

void	resolve_length(t_flags *flags, const char **format)
{
	if (!**format)
		return ;
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		flags->length = 1;
		(*format) += 2;
	}
	else if (**format == 'h')
	{
		flags->length = 2;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		flags->length = 3;
		(*format) += 2;
	}
	else if (**format == 'l')
	{
		flags->length = 4;
		(*format)++;
	}
	else if (**format == 'L')
	{
		flags->length = 5;
		(*format)++;
	}
}