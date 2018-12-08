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

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

typedef struct		s_flags
{
	int				left_align;
	int				add_plus;
	int				space;
	int				zero;
	int				hash;
	int				width;
	int				precision;
	enum {
		hh = 1,
		h,
		ll,
		l,
		L
	}				length;
}					t_flags;

int					ft_printf(const char *restrict format, ...);

#endif
