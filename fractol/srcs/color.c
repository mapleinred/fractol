/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:11:57 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 17:12:00 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_rgb(double r, double g, double b)
{
	int	rgb;

	rgb = 0x0;
	rgb <<= 8;
	rgb += r * 255;
	rgb <<= 8;
	rgb += g * 255;
	rgb <<= 8;
	rgb += b * 255;
	return (rgb);
}

int	colors(t_fractol *data, int iteration)
{
	if (iteration == data->max_iteration)
		return (0);
	if (data->color == 0)
		return (bw(data, iteration));
	if (data->color == 1)
		return (red(data, iteration));
	if (data->color == 2)
		return (blue(data, iteration));
	if (data->color == 3)
		return (c(data, iteration));
	if (data->color == 4)
		return (trip(data, iteration));
	return (bw(data, iteration));
}
