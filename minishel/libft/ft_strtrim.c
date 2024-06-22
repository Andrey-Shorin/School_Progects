/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:35 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:24:35 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_srav(char a, const char *set)
{
	while (*set != 0)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_srav(s1[i], set) && s1[i] != 0)
	{
		i++;
	}
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != 0 )
	{
		i++;
	}
	i--;
	while (i != -1 && ft_srav(s1[i], set))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*g;
	int		start;
	int		end;
	int		i;

	if (s1 == 0 || set == 0)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end == -1)
		start = 0;
	g = malloc(end - start + 2);
	if (g == 0)
		return (0);
	i = end - start + 1;
	g[i] = 0;
	i--;
	while (end != start - 1)
	{
		g[i] = s1[end];
		i--;
		end--;
	}
	return (g);
}
