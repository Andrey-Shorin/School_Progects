/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:21:43 by ytter             #+#    #+#             */
/*   Updated: 2022/02/15 18:50:57 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	fractj(double x0, double y0, t_mystr *a)
{
	double	temp;
	int		i;

	i = 0;
	while (i < a->repeats && y0 * y0 + x0 * x0 < 4)
	{
		i++;
		temp = x0;
		x0 = x0 * x0 - y0 * y0 + a->x0;
		y0 = 2 * temp * y0 + a->y0;
	}
	return (i);
}

int	fractm(double x0, double y0, t_mystr *a)
{
	double	x;
	double	y;
	int		i;
	double	temp;

	x = 0;
	y = 0;
	i = 0;
	while (i < a->repeats && y * y + x * x < 4)
	{
		i++;
		temp = x;
		x = x * x - y * y + x0;
		y = 2 * temp * y + y0;
	}
	return (i);
}

int	fractk(double x0, double y0, t_mystr *a)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	i = 0;
	y = 0;
	while (i < a->repeats && y * y + x * x < 4)
	{
		i++;
		temp = fabs(x * x - y * y);
		y = 2 * x * y + y0;
		x = temp + x0;
	}
	return (i);
}

int	fractb(double x0, double y0, t_mystr *a)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (i < a->repeats && y * y + x * x < 4)
	{
		i++;
		temp = x;
		x = x * x - y * y + x0;
		y = fabs(2 * temp * y) + y0;
	}
	return (i);
}
