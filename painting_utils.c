/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:52:07 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 13:04:42 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int iter, t_structures *struc)
{
	t_color_range	pal;
	int				rest;

	pal = struc->palette;
	rest = iter % 6;
	if (iter == struc->img.iter + 1)
		return (0);
	if (rest == 0)
		return (pal.c1.r * 256 * 256 + pal.c1.g * 256 + pal.c1.b);
	if (rest == 1)
		return (pal.c2.r * 256 * 256 + pal.c2.g * 256 + pal.c2.b);
	if (rest == 2)
		return (pal.c3.r * 256 * 256 + pal.c3.g * 256 + pal.c3.b);
	if (rest == 3)
		return (pal.c4.r * 256 * 256 + pal.c4.g * 256 + pal.c4.b);
	if (rest == 4)
		return (pal.c5.r * 256 * 256 + pal.c5.g * 256 + pal.c5.b);
	if (rest == 5)
		return (pal.c6.r * 256 * 256 + pal.c6.g * 256 + pal.c6.b);
	return (0);
}

int	get_color(int x, int y, t_structures *struc, int type)
{
	t_complex	c;
	int			iter;

	c = get_complex(x, y, &struc->img);
	iter = 0;
	if (type == 0 || type == 2)
		iter = fractal((t_complex) {0, 0}, c, struc);
	else if (type == 1)
		iter = fractal(c, (t_complex) {struc->img.c_re, 
			struc->img.c_im}, struc);
	return (color(iter, struc));
}

/*omple el color d'un pixel del color que se li passa*/
void	color_pixel_img(t_img img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
	{
		pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) pixel = color;
	}
}
