/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:25:07 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/10/30 12:25:10 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*ret_list;
	t_list	*temp;

	ret_list = NULL;
	if (lst && f && (ret_list = (t_list*)malloc(sizeof(t_list))))
	{
		ret_list = f(lst);
		temp = ret_list;
		lst = lst->next;
		while ((lst))
		{
			if ((temp->next = (t_list*)malloc(sizeof(t_list))))
			{
				temp->next = f(lst);
				temp = temp->next;
				lst = lst->next;
			}
		}
	}
	return (ret_list);
}
