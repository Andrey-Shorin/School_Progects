/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:24 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/25 17:02:17 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
