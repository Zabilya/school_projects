/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:13:08 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/28 14:13:08 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	list = tmp;
	while (lst->next)
	{
		if (!(tmp->next = (*f)(lst->next)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (list);
}
