/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:58 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:23:58 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	s = malloc(i + 1);
	if (s == 0)
		return (0);
	while (i != -1)
	{
		s[i] = str[i];
		i--;
	}
	return (s);
}
