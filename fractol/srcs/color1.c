/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:04:01 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 18:04:05 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	bw(t_fractol *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = linearscale(iteration, data->max_iteration, 0, 1);
	g = linearscale(iteration, data->max_iteration, 0, 1);
	b = linearscale(iteration, data->max_iteration, 0, 1);
	return (get_rgb(r, g, b));
}

int	red(t_fractol *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = linearscale(iteration, data->max_iteration, 0, 1);
	g = 0;
	b = 0;
	return (get_rgb(r, g, b));
}

int	blue(t_fractol *data, int iteration)
{
	double	r;
	double	g;
	double	b;

	r = 0;
	g = 0;
	b = linearscale(iteration, data->max_iteration, 0, 1);
	return (get_rgb(r, g, b));
}

int	c(t_fractol *data, int iteration)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = linearscale(iteration, data->max_iteration, 0, 1.0);
	r = fmod(9.4 * (1 - t) * t * t * t, 1.0);
	g = fmod(15.9 * (1 - t) * (1 - t) * t * t, 1.0);
	b = fmod(9.4 * (1 - t) * (1 - t) * (1 - t) * t, 1.0);
	return (get_rgb(r, g, b));
}

int	trip(t_fractol *data, int iteration)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = expontial_scale(iteration, data->max_iteration, data->luminosity);
	r = fmod(9.4 * (1 - t) * t * t * t, 1.0);
	g = fmod(15.9 * (1 - t) * (1 - t) * t * t, 1.0);
	b = fmod(9.4 * (1 - t) * (1 - t) * (1 - t) * t, 1.0);
	return (get_rgb(r, g, b));
}
