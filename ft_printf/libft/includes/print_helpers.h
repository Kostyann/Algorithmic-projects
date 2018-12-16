/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:40:47 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/16 13:40:49 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HELPERS_H
# define PRINT_HELPERS_H

# include "technical.h"

void	fix_precision(int *len, t_flags *flags, char **str, int neg);
void	get_un_string(char **str, t_flags *flags, va_list *ap, size_t base);
char	*btof(long double f, int precision, int hash);

#endif
