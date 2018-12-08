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

void 	resolve_flags(t_flags *flags, char **format)
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
}

void	resolve_width(t_flags *flags, char **format)
{
	if (**format && **format >= '0' && **format <= '9')
		(*format) += ft_strlen(ft_itoa(flags->width = ft_atoi(*format)));
}

void	resolve_precision(t_flags *flags, char **format)
{
	if (**format && **format == '.' && *(*format + 1) >= '0' && *(*format + 1) <= '9')
		(*format) += ft_strlen(ft_itoa(flags->precision = ft_atoi(++(*format))));
	else if (**format && **format == '.')
	{
		flags->precision = 1;
		(*format)++;
	}
}

void	resolve_length(t_flags *flags, char **format)
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