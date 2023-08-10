/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:56:45 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 15:44:51 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_structures	struc;

	if (argc != 2 && argc != 3)
		return (general_guide());
	if (argc == 2 && !create_mlx(&struc, argv))
		return (0);
	if (argc == 3 && !create_mlx(&struc, argv))
		return (0);
	if (struc.fractal == -1)
		return (fractals_guide());
	paint_fractal(&struc);
	mlx_hook(struc.win.win_ptr, DESTROY, 0, exit_window, &struc.win);
	mlx_hook(struc.win.win_ptr, KEY, 0, pressed_key, &struc.win);
	mlx_hook(struc.win.win_ptr, MOUSE_MOTION, 0, mouse_motion, &struc.win);
	mlx_hook(struc.win.win_ptr, MOUSE_CLICK, 0, mouse_click, &struc.win);
	mlx_loop(struc.win.mlx_ptr);
	return (0);
}
