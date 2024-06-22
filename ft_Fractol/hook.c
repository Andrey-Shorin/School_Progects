/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:23:11 by ytter             #+#    #+#             */
/*   Updated: 2022/02/15 14:35:56 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	frac(double x0, double y0, t_mystr *a)
{
	if (a->fractall == 'B')
		return (fractb(x0, y0, a));
	if (a->fractall == 'K')
		return (fractk(x0, y0, a));
	if (a->fractall == 'M')
		return (fractm(x0, y0, a));
	if (a->fractall == 'J')
		return (fractj(x0, y0, a));
	return (0);
}

int	key_hook(int key, t_mystr *myst)
{
	if (key == 24)
	{
		myst->scale = 1.5 * myst->scale;
		myst->flag = 1;
		return (0);
	}
	if (key == 27)
	{
		myst->scale = myst->scale / 1.5;
		myst->flag = 1;
		return (0);
	}
	if (key == 126)
	{
		myst->y += (-300.0) / (myst->scale);
		myst->flag = 1;
		return (0);
	}
	if (key == 125)
	{
		myst->y += (300.0) / (myst->scale);
		myst->flag = 1;
		return (0);
	}
	return (key_hook2(key, myst));
}

int	key_hook2(int key, t_mystr *myst)
{
	if (key == 123)
	{
		myst->x += (-300.0) / (myst->scale);
		myst->flag = 1;
	}
	if (key == 124)
	{
		myst->x += (300.0) / (myst->scale);
		myst->flag = 1;
	}
	if (key == 8)
	{
		if (myst->color_key != 6)
			myst->color_key ++;
		else
			myst->color_key = 0;
		myst->flag = 1;
	}
	if (key == 53)
	{
		mlx_destroy_image(myst->mlx, (myst->im)->img);
		mlx_destroy_window(myst->mlx, myst->win);
		exit(0);
	}
	return (0);
}

int	zoom(int button, int x1, int y1, t_mystr *myst)
{
	if (myst->flag != 1)
	{
	myst->x += ((double) x1 - 500.0) / (myst->scale);
	myst->y += ((double) y1 - 500.0) / (myst->scale);
	}
	if (button == 4)
		myst->scale = 1.5 * myst->scale;
	if (button == 5)
		myst->scale = myst->scale / 1.5;
	myst->flag = 1;
	return (0);
}
