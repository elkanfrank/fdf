/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 13:41:09 by efrank         #+#    #+#                */
/*   Updated: 2019/04/01 15:49:22 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1080
# define HEIGHT 960
# define PI 3.14159265

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef unsigned char	t_byte;

typedef struct	s_point {
	double		x;
	double		y;
	double		z;
	double		z_ori;
}				t_point;

typedef struct	s_color {
	t_byte		red;
	t_byte		green;
	t_byte		blue;
}				t_color;

typedef struct	s_max_z {
	float		min;
	float		mid;
	float		max;
	t_color		min_color;
	t_color		mid_color;
	t_color		max_color;
}				t_max_z;

typedef struct	s_slope {
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_slope;

typedef struct	s_size {
	float		zoom;
	int			width;
	int			height;
	int			y_rot;
	int			x_rot;
	int			z_rot;
	int			line_size;
	int			endian;
	int			bits_per_pixel;
	void		*init;
	void		*window;
	void		*image;
	char		*pixel_addr;
	t_max_z		max_z;
	t_point		**backup;
	t_point		**points;
}				t_size;

int				get_key(int key, t_size *data);
int				count_points(char *grid);
int				draw_points(t_size *data);
t_color			get_color_slope(double z, t_max_z color);
void			set_zoom(t_size *data);
void			isometric(t_size *data);
void			change_height(int amount, t_size *data);
double			clamp(double z);
t_max_z			map_colors_to_height(t_size *data);
t_point			**get_input(int argc, char **argv, t_size *dimensions);
t_point			**convert_to_points(int **grid, t_size dimensions);
t_point			*convert_grid(char **grid);
t_point			**rotate(double degrees, t_size *data, char axis);
t_point			**project_iso(t_size *data);

#endif
