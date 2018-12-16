/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:24:51 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:24:53 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNS_H
# define PRINT_FUNS_H

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int    print_d(t_flags *flags, va_list *ap);
int    print_b(t_flags *flags, va_list *ap);
int    print_o(t_flags *flags, va_list *ap);
int    print_u(t_flags *flags, va_list *ap);
int    print_x(t_flags *flags, va_list *ap);
int    print_c(t_flags *flags, va_list *ap);
int    print_s(t_flags *flags, va_list *ap);
int    print_p(t_flags *flags, va_list *ap);
int    print_f(t_flags *flags, va_list *ap);
int    print_else(t_flags *flags, va_list *ap);

#endif
