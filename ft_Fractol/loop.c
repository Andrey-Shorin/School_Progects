/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:34:57 by nposidon          #+#    #+#             */
/*   Updated: 2022/02/15 14:35:55 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	render_next_frame(t_mystr *myst)
{
	int		x;
	int		y;
	double	z;

	y = 0;
	x = 0;
	while (x < HEIGHT)
	{
		x++;
		while (y < WIDTH)
		{
			z = frac(((double)(x - HEIGHT / 2) / myst->scale) + myst->x,
					((double)(y - WIDTH / 2) / myst->scale) + myst->y, myst);
			my_mlx_pixel_put(myst->im, x, y,
				ft_color(z, myst->color_key, myst->repeats));
			y++;
		}
		y = 0;
	}
	mlx_put_image_to_window(myst->mlx, myst->win,
		(myst->im)->img, 0, 0);
	return (0);
}

int	ft_loop(t_mystr *a)
{
	if (a->flag == 0)
		return (0);
	mlx_clear_window(a->mlx, a->win);
	render_next_frame(a);
	a->flag = 0;
	return (0);
}

int	destroy(t_mystr *myst)
{
	mlx_destroy_image(myst->mlx, (myst->im)->img);
	mlx_destroy_window(myst->mlx, myst->win);
	exit(0);
}

void	createstr(t_mystr *a)
{
	a->scale = 100;
	a->x = -1.1;
	a->y = -1.1;
	a->color_key = 1;
	a->repeats = 300;
	a->fractall = 'O';
	a->flag = 1;
	a->x0 = 0.5;
	a->y0 = 0.5;
}

double	ftatio(char *b)
{
	double	a;
	double	c;
	int		i;

	i = 0;
	c = 10;
	a = 0;
	while (b[i] >= '0' && b[i] <= '9')
	{
			a = a * 10.0 + (double)(b[i] - '0');
			i++;
	}
	if (b[i] == 0)
		return (a);
	if (b[i] != '.' && b[i] != ',')
		exit (0);
	i ++;
	while (b[i] >= '0' && b[i] <= '9')
	{
		a = a + (double)(b[i] - '0') / c;
		c = c * 10.0;
		i++;
	}
	return (a);
}
