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
		printf("\n%d\n", printf("%+-55.8f %.7F", 1.42567999999, 1.42567999999));
	 printf("\n%d\n", ft_printf("%+-55.8f %.7F", 1.42567999999, 1.42567999999));

/*	 long double f = 2.000000;
	 unsigned long long hard = (unsigned long long) f;
	 printf("(hard = %lld)\n", hard); */

/*	double inf = 1/0.0;
	double minus_inf = -1/0.0;
	double minus_zero = -1/ inf ;
	double nan = 0.0/0.0;

	ft_printf("positive infinity: %f\n",inf);
	ft_printf("negative infinity: %f\n",minus_inf);
	ft_printf("negative zero: %f\n",minus_zero);
	ft_printf("not a number: %f\n",nan);

	ft_printf("+inf + 2.0 = %f\n",inf + 2.0);
	ft_printf("+inf - 10.1 = %f\n",inf - 10.1);
	ft_printf("+inf + -inf = %f\n",inf + minus_inf);
	ft_printf("0.0 * +inf = %f\n",0.0 * inf);
	ft_printf("1.0/-0.0 = %f\n",1.0/minus_zero);
	ft_printf("NaN + 1.0 = %f\n",nan + 1.0);
	ft_printf("NaN + NaN = %f\n",nan + nan); */

/*	float f = -12.5f;
	int * ptr_tmp = (int *)(&f);
	printf("%x\n",*(ptr_tmp));
	printf("\n%d\n", ft_printf("%b", *(ptr_tmp))); */

//	 int n = 4106;
//	 printf("%(16 - %x)\n", 26 % 16);
/*	    int c = 12;
	    int b = 8;
	    // XOR
		int a = (c | b) & (~(c & b));
	    printf("%d\n%d\n", a, c + b); */
		return (0);


}
