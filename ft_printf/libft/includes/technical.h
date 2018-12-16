/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:00:47 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/08 20:00:49 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TECHNICAL_H
# define TECHNICAL_H

# include "ft_printf.h"

char		*ft_itoa_long(long long n, int base);
char		*ft_itoa_ulong(unsigned long long n, int base);
int			add_prefix(char **str, int c, size_t len);
int			add_suffix(char **str, int c, size_t len);

#endif
