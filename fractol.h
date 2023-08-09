/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:37:01 by mnoguera          #+#    #+#             */
/*   Updated: 2023/08/08 14:46:11 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include "macros.h"

# include <stdio.h>

# define WIN_W (long double) 700
# define WIN_H (long double) 900

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movement;
}		t_win;

typedef struct s_img
{
	t_win		win;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
	int			iter;
	long double	x_inf;
	long double	y_inf;
	long double	x_sup;
	long double	y_sup;
	long double	c_re;
	long double	c_im;
}		t_img;

typedef struct s_complex
{
	long double		a;
	long double		b;
}		t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_color_range
{
	t_color	c0;
	t_color	c1;
	t_color	c2;
	t_color	c3;
	t_color	c4;
	t_color	c5;
	t_color	c6;
	t_color	c7;
}		t_color_range;

typedef struct s_structures
{
	t_win			win;
	t_img			img;
	t_color_range	palette;
	char			*type;
	int				fractal;
}		t_structures;

/*new_structures.c*/
int 				create_mlx(t_structures *struc, char *type);
t_img				new_img(t_win win);
t_win				new_win(char *str);

/*painting_utils.c*/
int					get_color(int x, int y, t_structures *struc, int type);
int					pixels_color(int x, int y, t_structures *struc);
void				color_pixel_img(t_img img, int x, int y, int color);

/*fractal.c*/
int					mandel_julia(t_complex z, t_complex c, int max_iter);
void    			paint_fractal(t_structures *struc);
void				paint_mandel(t_structures *struc);

/*complex_nums.c*/
t_complex			get_complex(int x, int y, t_img *img);
long double			module_squared(t_complex z);

/*color.c*/
t_color_range		palette(void);

/*events.c*/
int					exit_window(t_win *win);
int					pressed_key(int button, t_structures *struc);
int					mouse_motion(int x, int y, t_structures *struc);
int					mouse_click(int b, int x, int y, t_structures *struc);

/*events_utils.c*/
void				change_iter(int button, t_structures *struc);
void				move(int button, t_structures *struc);
void				zoom(int direction, int c_x, int c_y, t_structures *struc);
void				change_palette(t_structures *struc);

/*gides.c*/
void				events_guide(void);
int					fractals_guide(void);
int					general_guide(void);

#endif
