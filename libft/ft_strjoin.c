/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:06 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:24:06 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		i++;
	}
	return (i + 1);
}

static void	ft_cop(const char *s1, char *s2, int len)
{
	while (len != -1)
	{
		s2[len] = s1[len];
		len--;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_len(s1);
	j = ft_len(s2);
	ret = malloc(i + j - 1);
	if (ret == 0)
		return (0);
	ft_cop(s1, ret, i - 2);
	ft_cop(s2, ret + i - 1, j - 1);
	return (ret);
}
