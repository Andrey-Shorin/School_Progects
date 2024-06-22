/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterby <yterby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:09 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/28 17:33:49 by yterby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int len)
{
	if (dst == src)
		return (dst);
	while (len > 0)
	{
		len--;
		((char *)dst)[len] = ((char *)src)[len];
	}
	return (dst);
}
