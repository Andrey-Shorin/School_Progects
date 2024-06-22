/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:34:36 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/26 16:49:23 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_ret(t_list *start, t_list *list, void (*del)(void *))
{
	if (!list)
		ft_lstclear(&start, del);
	return (list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*t;
	t_list	*start;

	if (!lst)
		return (0);
	start = ft_lstnew(f(lst->content));
	if (!ft_ret(start, start, del))
		return (0);
	temp = start;
	lst = lst->next;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (!ft_ret(start, t, del))
			return (0);
		temp->next = t;
		temp = t;
		lst = lst->next;
	}
	return (start);
}
