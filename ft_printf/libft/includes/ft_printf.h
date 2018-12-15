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
	unsigned int				left_align: 1;
	unsigned int				add_plus: 1;
	unsigned int				space: 1;
	unsigned int				zero: 1;
	unsigned int				hash: 1;
	int				width;
	int				precision;
	enum {
		hh = 1,
		h,
		ll,
		l,
		L
	}				length;
	char 			id;
}					t_flags;

int					ft_printf(const char *restrict format, ...);

#endif
