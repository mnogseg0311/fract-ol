/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_structures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:51:51 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/10 17:11:16 by mnoguera         ###   ########.fr       */
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
	else if (ft_strncmp(type, "ship", 5) == 0)
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
	if (WIN_H > WIN_W)
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
	}
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

void	get_func(t_structures *struc, char **argv)
{
	char	*ptr;

	ptr = argv[2];
	ptr += 3;
	while (ft_isdigit(ptr[0]))
		ptr++;
	if (!ft_strncmp(ptr, "exp", 3))
		struc->func = 0;
	else if (!ft_strncmp(ptr, "sqrt", 4))
		struc->func = 1;
	else if (!ft_strncmp(ptr, "ln", 2))
		struc->func = 2;
	else if (!ft_strncmp(ptr, "sin", 3))
		struc->func = 3;
	else if (!ft_strncmp(ptr, "cos", 3))
		struc->func = 4;
}

int	get_flags(t_structures *struc, char **argv)
{
	char	*ptr;

	ptr = argv[2];
	if (ft_strncmp(ptr, "-m=", 3) != 0)
		return (0);
	ptr += 3;
	struc->m = 0;
	struc->func = -1;
	struc->m_2 = -1;
	if (ft_isdigit(ptr[0]))
		struc->m = ft_atoi(ptr);
	while (ft_isdigit(ptr[0]))
		ptr++;
	if (ptr[0] == '\0')
		return (1);
	get_func(struc, argv);
	while (ft_isalpha(ptr[0]))
		ptr++;
	if (ptr[0] == '\0')
		return (1);
	struc->m_2 = ft_atoi(ptr);
	return (1);
}

/*crea totes les estructures*/
int create_mlx(t_structures *struc, char **argv)
{
    t_win	win;
	t_img	img;
	
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
	struc->type = argv[1];
	struc->fractal = fractal_id(argv[1]);
	if (argv[2] && !get_flags(struc, argv))
			struc->m = -1;
	printf("m = %d, func = %d, m_2 = %d\n", struc->m, struc->func, struc->m_2);
    return (1);
}
