/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:41:40 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/28 15:41:41 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while ((*s1 || *s2) && (n != 0))
		{
			if ((unsigned char)*s1 != (unsigned char)*s2)
				return (0);
			s1++;
			s2++;
			n--;
		}
		return (1);
//		return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	}
	return (0);
}

int	main(void)
{
	printf("%i\n", ft_strnequ("ededeqdf", "", 0));
	printf("%i\n", ft_strncmp("ededeqdf", "", 0));
	printf("%i\n", strncmp("ededeqdf", "", 0));

	return (0);
}

/*
 *
 * if (s1 && s2 && (n != 0))
	{
		while ((*s1 || *s2) && (n != 0))
		{
			if ((unsigned char)*s1 != (unsigned char)*s2)
				return (0);
			s1++;
			s2++;
			n--;
		}
		return (1);
	}
	return (0);
 */