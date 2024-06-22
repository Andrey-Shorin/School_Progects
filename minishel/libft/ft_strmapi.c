/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:18 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:24:18 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = 0;
	while (len != -1)
	{
		str[len] = f((unsigned int)len, s[len]);
		len--;
	}
	return (str);
}
