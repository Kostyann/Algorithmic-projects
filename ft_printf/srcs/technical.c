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

#include "../libft/includes/technical.h"

static int	ft_len(long long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_long(long long n, int base)
{
	int		neg;
	int		len;
	char	*str;

	neg = 1;
	len = ft_len(n, base);
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
			str[--len] = (n % base) * neg + '0';
			n /= base;
		}
	}
	return (str);
}

char		*ft_itoa_ulong(unsigned long long n, int base)
{
	int					len;
	char				*str;
	unsigned long long	nbr;

	len = 1;
	nbr = n;
	while ((nbr /= base) != 0)
		len++;
	if (n == 0)
	{
		if ((str = ft_strnew(1)))
			str[0] = '0';
	}
	else if ((str = ft_strnew(len)))
	{
		while (n != 0)
		{
			if (n % base < 10)
				str[--len] = (n % base) + '0';
			else
				str[--len] = (n % base) + 'a' - 10;
			n /= base;
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
	if (!*str)
		*str = ft_strjoin(pref, "");
	else if (c == '0' && **str == '-')
	{
		*str = ft_strjoin(pref, (*str + 1));
		add_prefix(str, '-', 1);
	}
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
	if (!*str)
		*str = ft_strjoin("", suf);
	else
		*str = ft_strjoin(*str, suf);
	free(to_free);
	free(suf);
	return (ft_strlen(*str));
}
