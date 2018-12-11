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
//	    printf("\n%d\n", printf("@moulitest: %.d %.0d", 0, 0));
//	 printf("\n%d\n", ft_printf("@moulitest: %.d %.0d", 0, 0));
		printf("\n%d\n", printf("%-+22%", "string"));
	 printf("\n%d\n", ft_printf("%-+22.4lld", 12345));

//	 int n = 4106;
//	 printf("%(16 - %x)\n", 26 % 16);
/*	    int c = 12;
	    int b = 8;
	    // XOR
		int a = (c | b) & (~(c & b));
	    printf("%d\n%d\n", a, c + b); */
		return (0);


}
