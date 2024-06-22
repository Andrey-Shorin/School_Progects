/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:22:29 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/25 15:25:39 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list1;
	t_list	*temp;

	list1 = *lst;
	temp = *lst;
	if (!(*lst))
		return ;
	while (list1)
	{
		temp = list1->next;
		del(list1->content);
		free(list1);
		list1 = temp;
	}
	*lst = 0;
}
