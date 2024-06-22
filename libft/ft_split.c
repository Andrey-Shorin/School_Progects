/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:50 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/28 17:34:24 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**ft_del(char **g, char **start)
{
	if (g == start)
	{
		free(g);
		return (0);
	}
	g--;
	while (start != g)
	{
		free(*g);
		g--;
	}
	free(*g);
	free(g);
	return (0);
}

static int	ft_sum(char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		len = ft_len(s + i, c);
		if (!len)
		{
			i++;
			continue ;
		}
		i += len;
		j++;
	}
	return (j);
}

static char	**ft_coppy(const char *s, char **g, int len, char **temp)
{
	*g = malloc(len + 1);
	if (!g)
		return (ft_del(g, temp));
	(*g)[len] = 0;
	len--;
	while (len != -1)
	{
		(*g)[len] = s[len];
		len--;
	}
	return (g);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**g;
	char	**temp;

	if (s == 0)
		return (0);
	g = malloc(ft_sum(s, c) * sizeof(char *) + 1);
	temp = g;
	if (g == 0)
		return (0);
	while (*s)
	{
		len = ft_len(s, c);
		if (!len)
		{
			s++;
			continue ;
		}
		if (!ft_coppy(s, g, len, temp))
			return (0);
		g++;
		s += len;
	}
	*g = 0;
	return (temp);
}
