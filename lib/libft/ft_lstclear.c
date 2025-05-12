/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:12:55 by abahmani          #+#    #+#             */
/*   Updated: 2022/10/16 05:42:59 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*l;

	l = *lst;
	while (l)
	{
		(*lst) = (*lst)->next;
		ft_lstdelone(l, (*del));
		l = *lst;
	}
	*lst = NULL;
}
