/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:10:52 by nposidon          #+#    #+#             */
/*   Updated: 2022/01/24 13:10:53 by nposidon         ###   ########.fr       */
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
	ret = malloc(i + j);
	if (ret == 0)
		return (0);
	ft_cop(s1, ret, i - 2);
	ft_cop("/", ret + (i++) - 1, 0);
	ft_cop(s2, ret + i - 1, j - 1);
	return (ret);
}

static int	search(const char *str, const char *need, int len, int a)
{
	int	i;

	i = 0;
	while (str[i] == need[i] && need[i] != 0 && str[i] != 0
		&& (i < len - a || len == -1))
	{
		i++;
	}
	if (need[i] == 0 && need[i - 1] == str[i - 1])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *need, int len)
{
	char	*u;
	int		i;

	u = 0;
	i = 0;
	if (need[0] == 0)
		return ((char *)str);
	while ((i < len || len == -1) && str[i] != 0)
	{
		if (search(str + i, need, len, i))
			return ((char *)(str + i));
		i++;
	}
	return (u);
}
