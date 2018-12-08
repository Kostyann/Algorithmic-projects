/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:46:08 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/23 09:59:20 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int rt;

	rt = 1;
	if (nb > 12 || nb < 0)
		return (0);
	if (nb > 1)
		rt = nb * ft_recursive_factorial(nb - 1);
	return (rt);
}
