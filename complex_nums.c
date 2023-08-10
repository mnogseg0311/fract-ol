/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:50:46 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 15:03:46 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	module_squared(t_complex z)
{
	return (z.a * z.a + z.b * z.b);
}

t_complex	get_complex(int x, int y, t_img *img)
{
	long double  a;
    long double  b;

    a = img->x_inf + x * (img->x_sup - img->x_inf) / WIN_W;
    b = img->y_inf + y * (img->y_sup - img->y_inf) / WIN_H;
    return ((t_complex) {a, b});
}
