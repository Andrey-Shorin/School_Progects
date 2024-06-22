/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:59:25 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/11 06:02:47 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_delit_list(t_list *start)
{
	t_list	*temp1;

	temp1 = start->next;
	free(start);
	while (temp1)
	{
		start = temp1->next;
		free(temp1->exit);
		free(temp1);
		temp1 = start;
	}
	return (0);
}

int	ft_end_itter(t_list *start)
{
	int		i;
	int		p;
	t_list	*temp;

	i = 0;
	if (!start)
		return (-1);
	temp = start->next;
	while (temp)
	{
		p = temp->len;
		write(1, temp->exit, p);
		temp = temp->next;
		i += p;
	}
	ft_delit_list(start);
	return (i);
}
