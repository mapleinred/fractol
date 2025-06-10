/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:29:16 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/03 19:29:22 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoomin(t_fractol *data, int x, int y)
{
	double	xscale;
	double	yscale;

	xscale = (data->maxr - data->minr) / WIDTH;
	yscale = (data->maxim - data-> minim) / HEIGHT;
	data->minim += yscale * y * data->zoom;
	data->maxim -= yscale * (HEIGHT - y) * data->zoom;
	data->minr += xscale * x * data->zoom;
	data->maxr -= xscale * (WIDTH - x) * data->zoom;
}

void	zoomout(t_fractol *data, int x, int y)
{
	double	xscale;
	double	yscale;

	xscale = (data->maxr - data->minr) / WIDTH;
	yscale = (data-> maxim - data->minim) / HEIGHT;
	data->minim -= yscale * y * data->zoom;
	data->maxim += yscale * (HEIGHT - y) * data->zoom;
	data->minr -= xscale * x * data->zoom;
	data->maxr += xscale * (WIDTH - x) * data->zoom;
}

static void	inputhandle(t_fractol *data, int ac, char **av)
{
	if (ac != 2 && ac != 4)
		error();
	data->fractal = -1;
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		initmandelbrot(data);
	else if (ft_strncmp(av[1], "julia", 10) == 0)
		initjulia(data);
	else if (ft_strncmp(av[1], "burningship", 10) == 0)
		initburningship(data);
	if (data->fractal == -1)
		error();
	if (ac == 4)
	{
		data->jr = linearscale(ft_atod(av[2]), 99, 0, 1);
		data->ji = linearscale(ft_atod(av[3]), 99, 0, 1);
	}
}

static void	info(void)
{
	ft_printf("\n            Fractol      \n");
	ft_printf("\n                controls:\n");
	ft_printf("1 2 3 4 5      switch color\n");
	ft_printf("arrow keys awsd        move\n");
	ft_printf("r                     reset\n");
	ft_printf("u         lock/unlock julia\n");
	ft_printf("scroll                 zoom\n");
	ft_printf("leftmouse         new julia\n");
	ft_printf("esc                    exit\n");
	ft_printf("\n");
}

int	main(int ac, char *av[])
{
	t_fractol	data;

	inputhandle(&data, ac, av);
	initmlx(&data);
	info();
	mlx_loop_hook(data.mlx, loop_hoop, &data);
	mlx_loop(data.mlx);
}
