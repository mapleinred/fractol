/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:30:08 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 21:30:11 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initmandelbrot(t_fractol *data)
{
	data->fractal = 0;
	data->max_iteration = 20;
	data->minr = -2.51;
	data->maxr = 1.5;
	data->minim = -1.12;
	data->maxim = 1.12;
	data->color = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.5;
	data->luminosity = -1.3;
	data->lum_offset = 0.1;
	data->zoom = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	initjulia(t_fractol *data)
{
	data->fractal = 1;
	data->max_iteration = 20;
	data->minr = -2;
	data->maxr = 2;
	data->minim = -1.12;
	data->maxim = 1.12;
	data->jr = -0.904167;
	data->ji = -0.277926;
	data->color = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.25;
	data->luminosity = -1.3;
	data->lum_offset = 0.1;
	data->zoom = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	initburningship(t_fractol *data)
{
	data->fractal = 2;
	data->max_iteration = 20;
	data->minr = -2.51;
	data->maxr = 1.5;
	data->minim = -1.12;
	data->maxim = 1.12;
	data->color = 1;
	data->lum_min = -2.5;
	data->lum_max = 2.5;
	data->luminosity = -1.3;
	data->lum_offset = 0.1;
	data->zoom = 0.5;
	data->unlock = 0;
	data->animate = 1;
}

void	reset(t_fractol *data, int fractal)
{
	if (fractal == 0 || fractal == KEY_Z)
		initmandelbrot(data);
	else if (fractal == 1 || fractal == KEY_X)
		initjulia(data);
	else if (fractal == 2 || fractal == KEY_C)
		initburningship(data);
}

void	initmlx(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bit_per_pixel, \
	&data->line_length, &data->endian);
	mlx_hook(data->win, ON_KEYDOWN, 1, keyhook, data);
	mlx_hook(data->win, ON_DESTROY, 0, destroyhook, data);
	mlx_mouse_hook(data->win, mousehook, data);
	mlx_do_key_autorepeaton(data->mlx);
}

/*int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);

    win_ptr: A pointer to the window structure.
    funct_ptr: A pointer to the function that will handle mouse events.
    param: A parameter that will be passed to the callback function.
	The callback function should have the following signature:

c

int mouse_hook(int button, int x, int y, void *param);

    button: The mouse button that triggered the event (1 for left button, 2 for 
	right button, 3 for middle button).
    x, y: The coordinates of the mouse cursor when the event occurred.
    param: The parameter passed to the callback function.

Here is a simple example of how you might use mlx_mouse_hook:*/
