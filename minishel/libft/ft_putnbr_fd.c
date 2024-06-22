/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:40 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:23:41 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_pt(char *c, int i, int fd)
{
	i++;
	while (c[i] != '*')
	{
		write(fd, c + i, 1);
		i++;
	}
}

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

void	ft_putnbr_fd(int n, int fd)
{
	int		z;
	int		i;
	char	str[100];

	z = 1;
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
		str[i--] = '-';
	ft_pt(str, i, fd);
}
