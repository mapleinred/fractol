/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:52:03 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/07 12:52:06 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>

void	error(void)
{
	ft_printf("usage: /fractol (mandelbrot|julia|burningship)" "julia x y\n");
	exit(1);
}

void	mlxpixel(t_fractol *data, int x, int y, int colour)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dest = colour;
}

void	toggle(int *bool)
{
	if (*bool == 1)
		*bool = 0;
	else if (*bool == 0)
		*bool = 1;
}

double	linearscale(double n, double smax, double tmin, double tmax)
{
	double	srange;
	double	trange;
	double	factor;
	double	scaled;

	srange = smax;
	trange = tmax - tmin;
	factor = trange / srange;
	scaled = n * factor + tmin;
	return (scaled);
}

double	expontial_scale(double n, double smax, double lum)
{
	double	factor;
	double	scale;
	double	lumi;

	lumi = linearscale(lum, 1, 0.25, 0.6);
	factor = linearscale(n, smax, 0, 1);
	scale = 0.5 * pow(M_E, factor) - lumi;
	return (scale);
}
