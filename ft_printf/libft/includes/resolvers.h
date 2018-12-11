/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:14:38 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:14:40 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVERS_H
# define RESOLVERS_H

#include "ft_printf.h"

void 	resolve_flags(t_flags *flags, const char **format);
void	resolve_width(t_flags *flags, const char **format);
void	resolve_precision(t_flags *flags, const char **format);
void	resolve_length(t_flags *flags, const char **format);

#endif
