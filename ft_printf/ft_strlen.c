/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:15 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/11 06:05:15 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (c[i] != 0)
		i++;
	return (i);
}
