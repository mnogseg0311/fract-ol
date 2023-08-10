/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:14:38 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 11:03:16 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color_range	palette(void)
{
	t_color_range	pal;

	pal.c0 = (t_color) {255, 255, 255};
	pal.c1 = (t_color) {219, 76, 64};
	pal.c2 = (t_color) {240, 201, 135};
	pal.c3 = (t_color) {252, 131, 74};
	pal.c4 = (t_color) {137, 189, 158};
	pal.c5 = (t_color) {47, 151, 193};
	pal.c6 = (t_color) {186, 123, 161};
	return (pal);
}

