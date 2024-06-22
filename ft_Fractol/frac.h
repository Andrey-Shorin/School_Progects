/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:35:12 by nposidon          #+#    #+#             */
/*   Updated: 2022/02/15 14:56:50 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h> 
# include <math.h>
# define HEIGHT 1000
# define WIDTH 1000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct sssa {
	t_data	*im;
	void	*mlx;
	void	*win;
	double	x;
	double	y;
	double	scale;
	int		color_key;
	int		repeats;
	char	fractall;
	int		flag;
	double	x0;
	double	y0;
}	t_mystr;

int		render_next_frame(t_mystr *myst);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_color(int i, int color_key, int repeats);
int		fractj(double x0, double y0, t_mystr *a);
int		fractm(double x0, double y0, t_mystr *a);
int		fractk(double x0, double y0, t_mystr *a);
int		fractb(double x0, double y0, t_mystr *a);
int		frac(double x0, double y0, t_mystr *a);
int		key_hook(int key, t_mystr *myst);
int		key_hook2(int key, t_mystr *myst);
int		zoom(int button, int x1, int y1, t_mystr *myst);
int		render_next_frame(t_mystr *myst);
int		ft_loop(t_mystr *a);
int		destroy(t_mystr *myst);
void	createstr(t_mystr *a);
double	ftatio(char *b);
int		pars2(char **b, t_mystr *a);
int		pars(int s, char **b, t_mystr *a);
void	hello(void);
#endif