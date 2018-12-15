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
#include "includes/resolvers.h"
#include "includes/print_funs.h"

/*static void	setup_arr(t_handler *handlers)
{
	handlers['%'] = &ft_printf_handle_escape;
	handlers['s'] = &ft_printf_handle_str;
	handlers['S'] = &ft_printf_handle_wstr;
	handlers['p'] = &ft_printf_handle_ptr;
	handlers['d'] = &ft_printf_handle_int;
	handlers['D'] = &ft_printf_handle_long;
	handlers['i'] = &ft_printf_handle_int;
	handlers['o'] = &ft_printf_handle_octal;
	handlers['O'] = &ft_printf_handle_long;
	handlers['u'] = &ft_printf_handle_unsigned;
	handlers['U'] = &ft_printf_handle_long;
	handlers['x'] = &ft_printf_handle_hex;
	handlers['X'] = &ft_printf_handle_hex;
	handlers['c'] = &ft_printf_handle_char;
	handlers['C'] = &ft_printf_handle_wchar;
	handlers['b'] = &ft_printf_handle_binary;
	handlers['f'] = &ft_printf_handle_float;
	handlers['n'] = &ft_printf_handle_charswritten;
}

t_handler	ft_printf_get_handler(char c)
{
	static t_handler	*handlers = NULL;

	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		if (handlers != NULL)
			setup_arr(handlers);
	}
	return (handlers[(int)c]);
} */

typedef int			(*t_point)(t_flags*, va_list*);

t_point	ident_fun(const char *restrict str, t_flags *flags)
{
	t_point	fun_refs[15] = {&print_c, &print_s, &print_p, &print_b, &print_d,
								&print_d, &print_d, &print_o, &print_o, &print_u,
								&print_u, &print_x,
								&print_x, &print_f, &print_f};
	char	fun_chars[15] = {'c', 's', 'p', 'b', 'd', 'D', 'i',
							'o', 'O', 'u', 'U', 'x', 'X', 'f', 'F'};
	int		i;

	i = -1;
	if (str)
	{
		while (*str && ++i < 15)
			if (*str == fun_chars[i])
			{
				flags->id = fun_chars[i];
				return (fun_refs[i]);
			}
		if (*str)
		{
			flags->id = *str;
			return (&print_percent);
		}
	}
	return (NULL);
}

int		type_resolve(const char **format, va_list *ap)
{
	int		res;
	t_flags	flags;
	t_point	pointer;

	res = 0;
	ft_bzero(&flags, sizeof(flags));
	if (!(*(++*format)))
		return (0);
	resolve_flags(&flags, format);
	resolve_width(&flags, format);
	resolve_precision(&flags, format);
	resolve_length(&flags, format);
	if (!**format)
		return (0);
	if (!(pointer = ident_fun(*format, &flags)))
		return (0);
	else
		res = pointer(&flags, ap);
	(*format)++;
	return (res);
}

int		real_printf(const char *format, va_list *ap, int res)
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

int		ft_printf(const char *restrict format, ...)
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
