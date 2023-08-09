/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:14:38 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/03 16:25:40 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color_range	palette(void)
{
	t_color_range	pal;

	pal.c0 = (t_color) {255, 255, 255};
	pal.c1 = (t_color) {255, 102, 102};
	pal.c2 = (t_color) {255, 140, 102};
	pal.c3 = (t_color) {255, 255, 102};
	pal.c4 = (t_color) {102, 255, 102};
	pal.c5 = (t_color) {102, 255, 255};
	pal.c6 = (t_color) {179, 102, 255};
	pal.c7 = (t_color) {255, 102, 179};
	return (pal);
}

