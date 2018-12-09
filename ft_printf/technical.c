/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:58:18 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/08 19:58:20 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/technical.h"

static int	ft_len(long long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_long(long long n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 1;
	len = ft_len(n);
	if (n == 0)
	{
		if ((str = ft_strnew(1)))
			str[0] = '0';
		return (str);
	}
	if (n < 0)
		neg = -1;
	if ((str = ft_strnew(len)))
	{
		if (neg == -1)
			str[0] = '-';
		while (n != 0)
		{
			str[--len] = (n % 10) * neg + '0';
			n /= 10;
		}
	}
	return (str);
}

int			add_prefix(char **str, int c, size_t len)
{
	char *pref;
	char *to_free;

	pref = ft_strnew(len);
	pref = ft_memset(pref, c, len);
	to_free = *str;
	if (c == '0' && **str == '-')
	{
		*str = ft_strjoin(pref, (*str + 1));
		add_prefix(str, '-', 1);
	}
	else if (!*str)
		*str = ft_strjoin(pref, "");
	else
		*str = ft_strjoin(pref, *str);
	free(to_free);
	free(pref);
	return (ft_strlen(*str));
}

int			add_suffix(char **str, int c, size_t len)
{
	char *suf;
	char *to_free;

	suf = ft_strnew(len);
	suf = ft_memset(suf, c, len);
	to_free = *str;
	*str = ft_strjoin(*str, suf);
	free(to_free);
	free(suf);
	return (ft_strlen(*str));
}
