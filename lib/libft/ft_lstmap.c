/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urlooved && mat <urlooved_&&_mat@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:23 by mmeuric           #+#    #+#             */
/*   Updated: 2025/05/14 00:22:57 by urlooved &&      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	l = lst->next;
	head = ft_lstnew((*f)(lst->content));
	if (!head)
		return (NULL);
	new = head;
	lst = l;
	while (l)
	{
		new->next = ft_lstnew((*f)(l->content));
		if (!(new->next))
		{
			ft_lstclear(&head, (*del));
			return (NULL);
		}
		new = new->next;
		l = l->next;
		lst = l;
	}
	return (head);
}
