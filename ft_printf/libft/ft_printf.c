/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:41:48 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/19 18:41:51 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include "includes/print_funs.h"

typedef int	(*t_point)(t_flags*, va_list*);

static void	fun_refs(t_point *pointer)
{
	pointer['c'] = &print_c;
	pointer['s'] = &print_s;
	pointer['p'] = &print_p;
	pointer['b'] = &print_b;
	pointer['d'] = &print_d;
	pointer['D'] = &print_d;
	pointer['i'] = &print_d;
	pointer['o'] = &print_o;
	pointer['O'] = &print_o;
	pointer['u'] = &print_u;
	pointer['U'] = &print_u;
	pointer['x'] = &print_x;
	pointer['X'] = &print_x;
	pointer['f'] = &print_f;
	pointer['F'] = &print_f;
}

t_point		ident_fun(const char *restrict str, t_flags *flags)
{
	static t_point	*pointer = NULL;

	if (pointer == NULL)
	{
		pointer = ft_memalloc(sizeof(*pointer) * 256);
		if (pointer)
			fun_refs(pointer);
	}
	flags->id = *str;
	if (pointer[(int)*str])
		return (pointer[(int)*str]);
	else
		return (&print_else);
}

int			type_resolve(const char **format, va_list *ap)
{
	int		res;
	t_flags	flags;
	t_point	pointer;

	res = 0;
	ft_bzero(&flags, sizeof(flags));
	if (!(*(++*format)))
		return (0);
	resolve_flags(&flags, format, ap);
	if (!**format)
		return (0);
	pointer = ident_fun(*format, &flags);
	res = pointer(&flags, ap);
	(*format)++;
	return (res);
}

int			real_printf(const char *format, va_list *ap, int res)
{
	int		pr_chars;
	char	*perc;

	if (!*format)
		return (res);
	if (!(perc = ft_strchr(format, '%')))
	{
		while (*format)
		{
			ft_putchar(*format++);
			res++;
		}
	}
	else if (perc > format)
	{
		res += ft_strlen(format) - ft_strlen(perc);
		while (perc > format)
			ft_putchar(*format++);
	}
	if (*format && (pr_chars = type_resolve(&format, ap)))
		res = pr_chars + real_printf(format, ap, res);
	else
		res = real_printf(format, ap, res);
	return (res);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		sum;

	sum = 0;
	va_start(ap, format);
	if (*format)
		sum = real_printf(format, &ap, 0);
	va_end(ap);
	return (sum);
}
