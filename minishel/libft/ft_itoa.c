/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:22:13 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/26 16:47:44 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_n(int *n, int *i, char *str)
{
	int	z;

	z = 1;
	if (*n == -2147483648)
	{
		z = -1;
		str[*i] = '8';
		(*i)--;
		*n = - (*n / 10);
	}
	if (*n < 0)
	{
		*n = -(*n);
		z = -1;
	}
	if (*n == 0)
		str[(*i)--] = '0';
	return (z);
}

char	*ft_itoa(int n)
{
	int		z;
	int		i;
	char	str[100];

	i = 50;
	ft_memset(str, '*', 99);
	str[99] = 0;
	z = if_n(&n, &i, str);
	while (n)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	if (z == -1)
		str[i] = '-';
	return (ft_strtrim(str, "*"));
}
