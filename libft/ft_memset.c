/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:29 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/26 16:46:29 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	temp;
	unsigned char	*a;

	a = (unsigned char *) b;
	temp = (unsigned char) c;
	while (len != 0)
	{
		a[len - 1 ] = temp;
		len--;
	}
	return (b);
}
