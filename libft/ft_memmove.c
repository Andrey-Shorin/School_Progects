/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:18 by nposidon          #+#    #+#             */
/*   Updated: 2021/10/23 19:23:21 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *b, const void *a, int len)
{
	int	i;

	i = 0;
	if (a < b)
	{
		while (len != 0)
		{
			len--;
			((char *)b)[len] = ((char *)a)[len];
		}
		return (b);
	}
	if (a > b)
	{
		while (i < len)
		{
			((char *)b)[i] = ((char *)a)[i];
			i++;
		}
		return (b);
	}
	return (b);
}
