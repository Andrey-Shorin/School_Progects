/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:21:06 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/26 16:46:45 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(int num, int size)
{
	int		i;
	void	*g;

	i = 0;
	if (num < 0 || size < 0)
		return (0);
	g = malloc(num * size);
	if (g == 0)
		return (0);
	while (i < num * size)
	{
		((char *)g)[i] = 0;
		i++;
	}
	return (g);
}
