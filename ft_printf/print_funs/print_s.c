/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:33:01 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/07 20:33:03 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/print_funs.h"
#include "../libft/includes/technical.h"

int    print_s(t_flags *flags, va_list *ap)
{
	int 	i;
	int		len;
	char 	*temp;
	char	*str;

	i = 0;
	if (!(temp = va_arg(*ap, char*)))
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(temp);

	if (flags->precision == -1)
	{
		str = ft_strnew(0);
		len = 0;
	}
	else if (flags->precision && flags->precision < len)
	{
		str = ft_strndup(temp, flags->precision);
		len = flags->precision;
	}
	else
		str = ft_strdup(temp);

	if (flags->width > len)
	{
		if (flags->left_align)
			len = add_suffix(&str, ' ', flags->width - len);
		else
			len = add_prefix(&str, ' ', flags->width - len);
		len = flags->width;
	}

	ft_putnstr(str, len);
	if (*str)
		free(str);
	return (len);
}
