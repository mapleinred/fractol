/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:29:55 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/03 19:29:59 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include "keycodes.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 700

/* Key */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

typedef struct s_fracol
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*addr;

	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		max_iteration;
	int		color;
	int		fractal;
	int		unlock;
	int		animate;

	double	luminosity;
	double	lum_min;
	double	lum_max;
	double	lum_offset;
	double	jr;
	double	ji;
	double	minr;
	double	maxr;
	double	minim;
	double	maxim;
	double	zoom;
	double	i[3][2];
	double	pos[2];

}	t_fractol;

/*atod.c*/
double	ft_atod(char *str);

/*color.c*/
int		get_rgb(double r, double g, double b);
int		colors(t_fractol *data, int iteration);

/*color1.c */
int		bw(t_fractol *data, int iteration);
int		red(t_fractol *data, int iteration);
int		blue(t_fractol *data, int iteration);
int		c(t_fractol *data, int iteration);
int		trip(t_fractol *data, int interation);

/*hook.c*/
int		keyhook(int j, t_fractol *data);
int		destroyhook(t_fractol *data);
int		loop_hoop(t_fractol *data);
int		mousehook(int i, int x, int y, t_fractol *data);

/*init.c*/
void	initmandelbrot(t_fractol *data);
void	initjulia(t_fractol *data);
void	initburningship(t_fractol *data);
void	reset(t_fractol *data, int fractal);
void	initmlx(t_fractol *data);

/*move.c*/
void	move(t_fractol *data, int dir);

/*utils.c*/
void	error(void);
void	toggle(int *bool);
void	mlxpixel(t_fractol *data, int x, int y, int colour);
double	linearscale(double n, double smax, double tmin, double tmax);
double	expontial_scale(double n, double smax, double lum);

/*fractol.c*/
void	zoomin(t_fractol *data, int x, int y);
void	zoomout(t_fractol *date, int x, int y);
int		main(int ac, char *av[]);

/*burningship.c*/
int		putburningship(t_fractol *data);

/*mandelbrot.c*/
int		putmandelbreot(t_fractol *data);

/*julia.c*/
int		putjulia(t_fractol *data);

#endif
