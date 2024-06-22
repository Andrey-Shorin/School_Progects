/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:30:42 by ytter             #+#    #+#             */
/*   Updated: 2022/02/15 14:36:07 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	pars2( char **b, t_mystr *a)
{
	a->x0 = ftatio(b[2]);
	a->y0 = ftatio(b[3]);
	return (0);
}

int	pars(int s, char **b, t_mystr *a)
{
	if (s == 1)
	{
		hello();
		exit(0);
	}
	if (b[1][0] == 'J')
	{
		a->fractall = 'J';
		if (s == 4)
			pars2(b, a);
	}
	if (b[1][0] == 'B')
		a->fractall = 'B';
	if (b[1][0] == 'K')
		a->fractall = 'K';
	if (b[1][0] == 'M')
		a->fractall = 'M';
	if (a->fractall == 'O')
	{
		hello();
		exit(0);
	}
	return (0);
}

void	hello(void)
{
	write(1, "M to Mandelbrot\n", 16);
	write(1, "J to Julia\n", 11);
	write(1, "B to Ship\n", 10);
	write(1, "K to Kelt\n", 10);
}

int	main(int s, char **b)
{
	void	*mlx;
	void	*mlx_win;
	t_data	im;
	t_mystr	a;

	createstr(&a);
	pars(s, b, &a);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGHT, WIDTH, "fraclaol");
	im.img = mlx_new_image(mlx, HEIGHT, WIDTH);
	im.addr = mlx_get_data_addr(im.img, &im.bits_per_pixel,
			&im.line_length, &im.endian);
	a.im = &im;
	a.mlx = mlx;
	a.win = mlx_win;
	mlx_mouse_hook(mlx_win, zoom, &a);
	mlx_key_hook(mlx_win, key_hook, &a);
	mlx_hook(mlx_win, 17, 0, destroy, &a);
	mlx_loop_hook (mlx, ft_loop, &a);
	render_next_frame(&a);
	mlx_loop(mlx);
	return (0);
}
