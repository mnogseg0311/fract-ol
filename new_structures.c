/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:51:51 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 15:26:59 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*determina el tipus de fractal*/
int    fractal_id(char *type)
{
    if (ft_strncmp(type, "mandelbrot", 11) == 0)
        return (0);
	else if (ft_strncmp(type, "julia", 6) == 0)
		return (1);
	else if (ft_strncmp(type, "mandelbrot+julia", 17) == 0)
		return (2);
    else
        return (-1);
}

/*crea una nova imatge*/
t_img	new_img(t_win win)
{
	t_img	img;

	img.win = win;
	img.img_ptr = mlx_new_image(win.mlx_ptr, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img_ptr, &(img.bpp), 
			&(img.line_len), &(img.endian));
/*	if (WIN_H > WIN_W)
	{
		img.x_inf = -2;
		img.x_sup = 2;
		img.y_inf = -2 - 2 * (WIN_H - WIN_W) / WIN_W;
    	img.y_sup = 2 + 2 * (WIN_H - WIN_W) / WIN_W;
	}
	else
	{
		img.y_inf = -2;
		img.y_sup = 2;
		img.x_inf = -2 - 2 * (WIN_W - WIN_H) / WIN_H;
		img.x_sup = 2 + 2 * (WIN_W - WIN_H) / WIN_H;
	}*/
	img.y_inf = -2;
	img.y_sup = 2;
	img.x_inf = -2;
	img.x_sup = 2;
	img.iter = 11;
	img.c_re = 0.285;
	img.c_im = 0.01;
	return (img);
}

/*crea una nova pantalla*/
t_win	new_win(char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, WIN_W, WIN_H, str), 1});
}

/*crea totes les estructures*/
int create_mlx(t_structures *struc, char *type)
{
    t_win	win;
	t_img	img;
	int		fractal;

	fractal = fractal_id(type);
	if (fractal == -1)
		return (-1);
	win = new_win("fract-ol");
	if (!win.mlx_ptr || !win.win_ptr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	img = new_img(win);
	if (!img.img_ptr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
    struc->img = img;
    struc->win = win;
	struc->palette = palette();
	struc->type = type;
	struc->fractal = fractal;
    return (1);
}
