/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_str1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:23 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/12 16:34:24 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_16(int a)
{
	if (a < 0)
		a = -a;
	if (a < 10)
		return ('0' + a);
	return ('a' + a - 10);
}

char	ft_16a(int a)
{
	if (a < 10)
		return ('0' + a);
	return ('A' + a - 10);
}

void	int_to_str(long a, char *str)
{
	char	s[100];
	int		i;
	int		d;

	i = 0;
	d = 0;
	s[i] = 0;
	i++;
	if (a < 0)
	{
		d = -1;
		a = -a;
	}
	while ((a != 0 || i == 1) && i < 99)
	{
		s[i] = (a % 10) + '0';
		a = a / 10;
		i ++;
	}
	if (d == -1)
		s[i++] = '-';
	ft_revers_coppy(s + i - 1, str);
}

void	un_int_to_str(unsigned long a, char *str)
{
	char	s[100];
	int		i;

	i = 0;
	s[i] = 0;
	i++;
	while ((a != 0 || i == 1) && i < 99)
	{
		s[i] = (a % 10) + '0';
		a = a / 10;
		i ++;
	}
	ft_revers_coppy(s + i - 1, str);
}

void	pointer_to_str16(unsigned long long a, char *str)
{
	char	s[100];
	int		i;

	i = 0;
	s[i] = 0;
	i++;
	while ((a != 0 || i == 1) && i < 99)
	{
		s[i] = ft_16(a % 16);
		a = a / 16;
		i ++;
	}
	str[0] = '0';
	str[1] = 'x';
	ft_revers_coppy(s + i - 1, str + 2);
}
