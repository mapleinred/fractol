/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:13:45 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/07 17:13:47 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	keyhook(int j, t_fractol *data)
{
	ft_printf("Pressed key code: %d\n", j);
	if (j == KEY_ESCAPE)
		destroyhook(data);
	else if (j == KEY_SPACE)
		toggle(&data->animate);
	else if (j == KEY_U)
		toggle(&data->unlock);
	else if (j == KEY_R)
		reset(data, data->fractal);
	else if (j == KEY_Z || j == KEY_X || j == KEY_C)
		reset(data, j);
	else if (j == KEY_PLUS)
		data->max_iteration += 5;
	else if (j == KEY_MINUS)
		data->max_iteration -= 5;
	else if (j >= KEY_1 && j <= KEY_5)
		data->color = j - KEY_1;
	else if ((j >= KEY_LEFT && j <= KEY_DOWN) || j == KEY_A \
	|| j == KEY_D || j == KEY_S || j == KEY_W)
		move(data, j);
	return (j);
}

int	destroyhook(t_fractol *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

int	loop_hoop(t_fractol *data)
{
	int	x;
	int	y;

	if (data->unlock)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
		data->jr = linearscale(x, WIDTH, data->minr, data->maxr);
		data->ji = linearscale(y, HEIGHT, data->minim, data->maxim);
	}
	if (data->animate && data->color == 4)
	{
		if (data->luminosity > data->lum_max)
			data->luminosity = data->lum_min;
		data->luminosity += data->lum_offset;
	}
	if (data->fractal == 0)
		putmandelbreot(data);
	else if (data->fractal == 1)
		putjulia(data);
	else if (data->fractal == 2)
		putburningship(data);
	return (0);
}

int	mousehook(int i, int x, int y, t_fractol *data)
{
	if (i == 1)
	{
		if (data->unlock == 1)
			data->unlock = 0;
		else
		{
			data->jr = linearscale(x, WIDTH, data->minr, data->maxr);
			data->ji = linearscale(y, HEIGHT, data->minim, data->maxim);
		}
	}
	if (i == 4)
		zoomin(data, x, y);
	if (i == 5)
		zoomout(data, x, y);
	return (0);
}
