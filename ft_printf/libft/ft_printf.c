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

// Include the stdarg.h
// Prototype: int (fixedparam, ...)
// Define a va_list variable
// Begin and end argu list with va_start and va_end

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include "includes/resolvers.h"
#include "includes/print_funs.h"

typedef int			(*fun_point)(t_flags*, va_list*);

fun_point ident_fun(const char *restrict str)
{
	fun_point fun_refs[11] = {&print_c,  &print_s, &print_p, &print_d,
										 	&print_i, &print_o, &print_u, &print_x,
										 	&print_bigx, &print_f, &print_percent};
	char	fun_chars[11] = {'c', 's', 'p', 'd', 'i', 'o', 'u', 'x', 'X', 'f', '%'};
	int		i;

	i = -1;
	while (*str && ++i < 11)
		if (*str == fun_chars[i])
        	return fun_refs[i];
	return (NULL);
}

int		type_resolve(char **format, va_list *ap)
{
	int 	res = 0;
	t_flags flags;
	fun_point pointer;

	ft_bzero(&flags, sizeof(flags));
	if (!(*(++*format)))
		return (0);
	resolve_flags(&flags, format);
	resolve_width(&flags, format);
	resolve_precision(&flags, format);
	resolve_length(&flags, format);
	if (!**format)
		return (0);
	if (!(pointer = ident_fun(*format)))
		return (0);
	else
		res = pointer(&flags, ap);
	(*format)++;
	return (res);
}

int     real_printf(const char *format, va_list *ap, int res)
{
    int		pr_chars;
    char    *perc;

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
	if (*format && (pr_chars = type_resolve((char**)&format, ap)))
        	res = pr_chars + real_printf(format, ap, res);
	else
        	res = real_printf(format, ap, res);
    return (res);
}

int     ft_printf(const char *restrict format, ...)
{
    va_list ap;
    int     sum;

    sum = 0;
    va_start(ap, format);
    if (*format)
	    sum = real_printf(format, &ap, 0);
    va_end(ap);
    return (sum);
}
