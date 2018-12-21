/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:07:46 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:07:47 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_flags
{
	unsigned int	left_align: 1;
	unsigned int	add_plus: 1;
	unsigned int	space: 1;
	unsigned int	zero: 1;
	unsigned int	hash: 1;
	int				width;
	int				precision;
	enum {
		hh = 1,
		h,
		ll,
		l,
		L
	}				length;
	char			id;
}					t_flags;

int					ft_printf(const char *restrict format, ...);

/* print functions of different types */

int	print_d(t_flags *flags, va_list *ap);
int	print_b(t_flags *flags, va_list *ap);
int	print_o(t_flags *flags, va_list *ap);
int	print_u(t_flags *flags, va_list *ap);
int	print_x(t_flags *flags, va_list *ap);
int	print_c(t_flags *flags, va_list *ap);
int	print_s(t_flags *flags, va_list *ap);
int	print_p(t_flags *flags, va_list *ap);
int	print_f(t_flags *flags, va_list *ap);
int	print_else(t_flags *flags, va_list *ap);

/* short hand for defining a length of fractional part of float number */

# define FRACTION_LEN (len - (dot - str) - 1)

/* technical fun's for printf */

void		resolve_flags(t_flags *flags, const char **format, va_list *ap);
char		*ft_itoa_long(long long n, int base);
char		*ft_itoa_ulong(unsigned long long n, int base);
int			add_prefix(char **str, int c, size_t len);
int			add_suffix(char **str, int c, size_t len);
void		fix_precision(int *len, t_flags *flags, char **str, int neg);
void		get_un_string(char **str, t_flags *flags, va_list *ap, size_t base);
char		*btof(long double f, int precision, int hash);

#endif
