/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:50 by nposidon          #+#    #+#             */
/*   Updated: 2022/01/22 06:32:28 by nposidon         ###   ########.fr       */
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

static char	**ft_del(char **end, char **start)
{
	if (end == start)
	{
		free(end);
		return (0);
	}
	end--;
	while (start != end)
	{
		free(*end);
		end--;
	}
	free(*end);
	free(end);
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

static char	**ft_coppy(const char *s, char **end, int len, char **temp)
{
	*end = malloc(len + 2);
	if (!end)
		return (ft_del(end, temp));
	(*end)[len] = 0;
	len--;
	while (len != -1)
	{
		(*end)[len] = s[len];
		len--;
	}
	return (end);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**end;
	char	**temp;

	if (s == 0)
		return (0);
	end = malloc(ft_sum(s, c) * sizeof(char *) + 1);
	temp = end;
	if (end == 0)
		return (0);
	while (*s)
	{
		len = ft_len(s, c);
		if (!len)
		{
			s++;
			continue ;
		}
		if (!ft_coppy(s, end, len, temp))
			return (0);
		end++;
		s += len;
	}
	*end = 0;
	return (temp);
}
