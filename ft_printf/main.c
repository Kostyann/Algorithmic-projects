/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:27:00 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/30 16:27:28 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/ft_printf.h"

int     ft_printf(const char *restrict format, ...);

int     main(void)
{
	    printf("\n%d\n", ft_printf("-2%-2.3diou", 1));
/*	    int c = 12;
	    int b = 8;
	    // XOR
		int a = (c | b) & (~(c & b));
	    printf("%d\n%d\n", a, c + b); */
		return (0);


}
