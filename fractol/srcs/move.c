/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:38:51 by xzhang            #+#    #+#             */
/*   Updated: 2024/01/12 12:38:54 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	moveleft(t_fractol *data)
{
	double	scale;

	scale = (data->maxr - data->minr) / WIDTH;
	data->maxr -= scale * 10;
	data->minr -= scale * 10;
}

static void	moveright(t_fractol *data)
{
	double	scale;

	scale = (data->maxr - data->minr) / WIDTH;
	data->maxr += scale * 10;
	data->minr += scale * 10;
}

static void	moveup(t_fractol *data)
{
	double	scale;

	scale = (data->maxim - data->minim) / HEIGHT;
	data->maxim -= scale * 10;
	data->minim -= scale * 10;
}

static void	movedown(t_fractol *data)
{
	double	scale;

	scale = (data->maxim - data->minim) / HEIGHT;
	data->maxim += scale * 10;
	data->minim += scale * 10;
}

void	move(t_fractol *data, int dir)
{
	if (dir == KEY_LEFT || dir == KEY_A)
		moveleft(data);
	else if (dir == KEY_RIGHT || dir == KEY_D)
		moveright(data);
	else if (dir == KEY_UP || dir == KEY_W)
		moveup(data);
	else if (dir == KEY_DOWN || dir == KEY_S)
		movedown(data);
}
