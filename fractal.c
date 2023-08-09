/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:51:20 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 15:38:51 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*calcula el nombre d'iteracions pel mandelbrot i julia*/
int mandel_julia(t_complex z, t_complex c, int max_iter)
{
	int			iter;
	t_complex	z_aux;

	iter = 0;
	while (iter <= max_iter && module_squared(z) <= 4)
	{
		z_aux = z;
		z.a = z_aux.a * z_aux.a - z_aux.b * z_aux.b + c.a;
		z.b = 2 * z_aux.a * z_aux.b + c.b;
		iter++;
	}
	return (iter);
}

/*itera pixel per pixel de la pantalla*/
void    paint_fractal(t_structures *struc)
{
    int x;
	int y;
	int	color;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			color = get_color(x, y, struc, struc->fractal);
			if (color == -1)
			{
				fractals_guide();
				return ;
			}
			color_pixel_img(struc->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(struc->img.win.mlx_ptr,
			struc->img.win.win_ptr, struc->img.img_ptr, 0, 0);
}
