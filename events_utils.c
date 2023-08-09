/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:49:21 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 14:45:17 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_iter(int button, t_structures *struc)
{
	if (button == PLUS)
		struc->img.iter += 42;
	else
		struc->img.iter -= 42;
	paint_fractal(struc);
}

void	move(int button, t_structures *struc)
{
	long double	distance;

	distance = 42 * (struc->img.x_sup - struc->img.x_inf) / WIN_W;
	if (button == UP)
	{
		struc->img.y_inf += distance;
		struc->img.y_sup += distance;
	}
	else if (button == DOWN)
	{
		struc->img.y_inf -= distance;
		struc->img.y_sup -= distance;
	}
	else if (button == RIGHT)
	{
		struc->img.x_inf += distance;
		struc->img.x_sup += distance;
	}
	else
	{
		struc->img.x_inf -= distance;
		struc->img.x_sup -= distance;
	}
	paint_fractal(struc);
}

/*zoom, direction 1 es in, -1 es out*/
void	zoom(int direction, int c_x, int c_y, t_structures *struc)
{
	long double	dist;
	long double	width;
	long double	height;

	dist = direction * 42;
	width = struc->img.x_sup - struc->img.x_inf;
	height = struc->img.y_sup - struc->img.y_inf;
	if (c_x == -42 && c_y == -42)
	{
		struc->img.x_inf += dist * width / WIN_W;
		struc->img.x_sup -= dist * width / WIN_W;
		struc->img.y_inf += dist * height / WIN_H;
		struc->img.y_sup -= dist * height / WIN_H;
	}
	else
	{
		struc->img.x_inf += c_x * dist * width / (WIN_W * WIN_W);
		struc->img.x_sup = struc->img.x_inf + width - width * dist / WIN_W;
		struc->img.y_inf += c_y * dist * height / (WIN_H * WIN_H);
		struc->img.y_sup = struc->img.y_inf + height - height * dist / WIN_H;
	}
	paint_fractal(struc);
}

void	change_palette(t_structures *struc)
{
	t_color	aux;

	aux = struc->palette.c1;
	struc->palette.c1 = struc->palette.c2;
	struc->palette.c2 = struc->palette.c3;
	struc->palette.c3 = struc->palette.c4;
	struc->palette.c4 = struc->palette.c5;
	struc->palette.c5 = struc->palette.c6;
	struc->palette.c6 = struc->palette.c7;
	struc->palette.c7 = aux;
	paint_fractal(struc);
}

