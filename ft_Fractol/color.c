/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:33 by ytter             #+#    #+#             */
/*   Updated: 2022/02/15 14:35:59 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	rbg(int r, int g, int b)
{
	return (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_color(int i, int color_key, int repeats)
{
	int		n;
	double	t;
	int		s;

	t = (double)i / (double)repeats;
	n = i;
	s = 100;
	if (color_key == 0)
		return (((n * 255 / 10) << 16) + (i << 21) + (i << 10) + i * 8);
	if (color_key == 1)
		return (((n * 255 / 10) << 16) + ((n * 255 / 10) << 8) + n * 25 / 10);
	if (color_key == 2)
		return (((n * 255 / 40) << 16) + ((n * 255 / 10) << 8) + n * 255 / 300);
	if (color_key == 3)
		return (((n * 80 / s) << 8) + ((n * 255 / s) << 16) + n * 145 / s);
	if (color_key == 4)
		return (rbg((75.5 * 0.1 * (n) + 1),
				(125.5 * 0.1 * (n) + 1), (34.5 * (1 - 0.1 * (n)))));
	if (color_key == 5)
		return (((n * 255 / s) << 2) + ((n * 255 / s) << 16) + n * 255 / s);
	return ((int)((134 - 6) * (1 - t) * t * t * t * 255) *
		(int)((134) * t * t * (1 - t) * (1 - t) * 255) *
		(int)((134 - 6.5) * (1 - t) * (1 - t) * (1 - t) * t * 255));
}
