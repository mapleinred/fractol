/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:31:25 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 21:31:28 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	calc(t_fractol *data, double x_c, double y_c)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	x_c = linearscale(x_c, WIDTH, data->minr, data->maxr);
	y_c = linearscale(y_c, HEIGHT, data->minim, data->maxim);
	while (x * x + y * y <= 4 && i < data->max_iteration)
	{
		tmp = fabs(x * x - y * y) + x_c;
		y = 2 * fabs(x * y) + y_c;
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

int	putburningship(t_fractol *data)
{
	if (data->max_iteration <= 0)
		data->max_iteration = 5;
	picture(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
