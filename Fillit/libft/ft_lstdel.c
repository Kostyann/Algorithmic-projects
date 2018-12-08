/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:59:36 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/29 16:59:38 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*temp;

	if (alst)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			temp = *alst;
			*alst = (*alst)->next;
			free(temp);
		}
		*alst = NULL;
	}
}
