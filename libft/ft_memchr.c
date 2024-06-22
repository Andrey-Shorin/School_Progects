/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:22:54 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:22:55 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *S, int C, int len)
{
	int				i;
	unsigned char	c;
	unsigned char	*s;

	c = (unsigned char) C;
	s = (unsigned char *) S;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
