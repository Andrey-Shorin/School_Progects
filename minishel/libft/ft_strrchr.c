/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:24:28 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:24:28 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int C)
{
	int				i;
	unsigned char	c;
	unsigned char	*h;

	i = 0;
	h = 0;
	c = (unsigned char) C;
	while (s[i] != 0)
	{
		if (s[i] == c)
			h = (unsigned char *)(s + i);
		i++;
	}
	if (s[i] == c)
		h = (unsigned char *)(s + i);
	return ((char *)h);
}
