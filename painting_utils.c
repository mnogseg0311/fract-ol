/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:52:07 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 15:31:28 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sub_color(t_color col1, t_color col2, int divisions, int rest)
{
	t_color color;

	if (col1.r > col2.r)
		color.r = col2.r + rest * (col1.r - col2.r) / divisions;
	else
		color.r = col1.r + rest * (col2.r - col1.r) / divisions;
	if (col1.g > col2.g)
		color.g = col2.g + rest * (col1.g - col2.g) / divisions;
	else
		color.g = col1.g + rest * (col2.g - col1.g) / divisions;
	if (col1.b > col2.b)
		color.b = col2.b + rest * (col1.b - col2.b) / divisions;
	else
		color.b = col1.b + rest * (col2.b - col1.b) / divisions;
	return (color.r * 256 * 256 + color.g * 256 + color.b);
}

int	color(int iter, t_structures *struc)
{
	t_color_range	pal;
	int				len;

	pal = struc->palette;
	len = struc->img.iter / 7;
	if (iter < len)
		return (sub_color(pal.c0, pal.c1, len, iter));
	else if (iter < 2 * len)
		return (sub_color(pal.c1, pal.c2, len, iter % len));
	else if (iter < 3 * len)
		return (sub_color(pal.c2, pal.c3, len, iter % len));
	else if (iter < 4 * len)
		return (sub_color(pal.c3, pal.c4, len, iter % len));
	else if (iter < 5 * len)
		return (sub_color(pal.c4, pal.c5, len, iter % len));
	else if (iter < 6 * len)
		return (sub_color(pal.c5, pal.c6, len, iter % len));
	else if (iter < struc->img.iter - 1)
		return (sub_color(pal.c6, pal.c7, len, iter % len));
	return (0);
}

int	get_color(int x, int y, t_structures *struc, int type)
{
	t_complex	c;
	int			iter;

	c = get_complex(x, y, &struc->img);
	iter = 0;
	if (type == 0)
		iter = mandel_julia((t_complex) {0, 0}, c, struc->img.iter);
	else if (type == 1)
		iter = mandel_julia(c, (t_complex) {struc->img.c_re, 
			struc->img.c_im}, struc->img.iter);
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
