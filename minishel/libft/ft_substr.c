/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:39 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/26 16:47:02 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_chek(char *ret, char const *s, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (i < start)
	{
		if (s[i] == 0)
		{
			ret[0] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*ret;

	if (s == 0)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = malloc(len + 1);
	if (ret == 0)
		return (0);
	if (ft_chek(ret, s, start))
		return (ret);
	ret[len] = 0;
	len--;
	while (len != -1)
	{
		ret[len] = s[len + start];
		len --;
	}
	return (ret);
}
