/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_str2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:40 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/12 16:34:42 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_to_str16(long a, char *str)
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
	ft_revers_coppy(s + i - 1, str);
}

void	int_to_str16a(long a, char *str)
{
	char	s[100];
	int		i;

	i = 0;
	s[i] = 0;
	i++;
	while ((a != 0 || i == 1) && i < 99)
	{
		s[i] = ft_16a(a % 16);
		a = a / 16;
		i ++;
	}
	ft_revers_coppy(s + i - 1, str);
}

void	ft_revers_coppy(const char *s, char *str)
{
	while (*s)
	{
		*str = *s;
		s --;
		str ++;
	}
	*str = 0;
}
