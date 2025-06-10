/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:30:51 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 21:30:55 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	calc(t_fractol *data, double x_c, double y_c)
{
	double	x;
	double	y;
	int		i;
	double	tmp;

	i = 0;
	x = linearscale(x_c, WIDTH, data->minr, data->maxr);
	y = linearscale(y_c, HEIGHT, data->minim, data->maxim);
	while (x * x + y * y <= 4.5 && i < data->max_iteration)
	{
		tmp = x * x - y * y + data->jr;
		y = (x + x) * y + data->ji;
		x = tmp;
		i++;
	}
	return (i);
}

static void	picture(t_fractol *data)
{
	int	x;
	int	y;
	int	color;
	int	iteration;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iteration = calc(data, x, y);
			color = colors(data, iteration);
			mlxpixel(data, x, y, color);
			y++;
		}
		x++;
	}
}

int	putjulia(t_fractol *data)
{
	if (data->max_iteration <= 0)
		data->max_iteration = 5;
	picture(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
