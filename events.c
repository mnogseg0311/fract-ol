/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:28:12 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 14:58:38 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_window(t_win *win)
{
	if (win)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit (EXIT_SUCCESS);
}

int	pressed_key(int b, t_structures *struc)
{
	if (b == ESC)
		exit_window(&struc->win);
	else if (b == PLUS || b == MINUS)
		change_iter(b, struc);
	else if (b == UP || b == DOWN || b == LEFT || b == RIGHT)
		move(b, struc);
	else if (b == ENTER)
		zoom(1, -42, -42, struc);
	else if (b == SPC)
		zoom(-1, -42, -42, struc);
	else if (b == TAB)
		change_palette(struc);
	else
		events_guide();
	return (0);
}

int	mouse_motion(int x, int y, t_structures *struc)
{
	t_complex	c;

	if (struc->fractal == 1 && struc->win.movement == 1)
	{
		if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
		{
			c = get_complex(x, y, &struc->img);
			struc->img.c_re = c.a;
			struc->img.c_im = c.b;
			paint_fractal(struc);
		}
	}
	return (0);
}

int	mouse_click(int b, int x, int y, t_structures *struc)
{
	if (b == SCROLL_UP)
		zoom(1, x, y, struc);
	else if (b == SCROLL_DOWN)
		zoom(-1, x, y, struc);
	else if (b == LEFT_CLICK || b == RIGHT_CLICK)
	{
		if (struc->win.movement == 0)
			struc->win.movement = 1;
		else
			struc->win.movement = 0;
	}
	return (0);
}
