/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 13:19:14 by efrank         #+#    #+#                */
/*   Updated: 2019/03/27 18:14:16 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_values(t_point *a, t_point *b, t_size *data, t_slope *slope)
{
	a->x = roundf(a->x * data->zoom);
	a->y = roundf(a->y * data->zoom);
	b->x = roundf(b->x * data->zoom);
	b->y = roundf(b->y * data->zoom);
	slope->dx = fabs(b->x - a->x);
	slope->dy = fabs(b->y - a->y);
	slope->sx = a->x < b->x ? 1 : -1;
	slope->sy = a->y < b->y ? 1 : -1;
	if (slope->dx > slope->dy)
		slope->err = slope->dx;
	else
		slope->err = -1 * slope->dy;
}

void		put_pixel(t_size data, int x, int y, t_color color)
{
	int i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = x * (data.bits_per_pixel / 8) + (y * data.line_size);
		data.pixel_addr[i] = color.blue;
		data.pixel_addr[++i] = color.green;
		data.pixel_addr[++i] = color.red;
	}
}

static void	next_pixel(t_slope *slope, t_point *current)
{
	slope->e2 = slope->err;
	if (slope->e2 > -1 * slope->dx)
	{
		slope->err -= slope->dy;
		current->x += slope->sx;
	}
	if (slope->e2 < slope->dy)
	{
		slope->err += slope->dx;
		current->y += slope->sy;
	}
}

static void	draw_line(t_point a, t_point b, t_size data)
{
	t_slope	slope;
	t_point current;
	double	delta_z;

	set_values(&a, &b, &data, &slope);
	slope.err /= 2;
	current.x = a.x;
	current.y = a.y;
	current.z = a.z_ori;
	if (fabs(b.x - a.x) > fabs(b.y - a.y))
		delta_z = ((double)b.z_ori - a.z_ori) / fabs(b.x - a.x);
	else
		delta_z = ((double)b.z_ori - a.z_ori) / fabs(b.y - a.y);
	while (current.x != b.x || current.y != b.y)
	{
		put_pixel(data, current.x + (WIDTH / 2) - (data.width * data.zoom / 2),
		current.y + (HEIGHT / 2) - (data.height * data.zoom / 2),
		get_color_slope(current.z, data.max_z));
		slope.e2 = slope.err;
		next_pixel(&slope, &current);
		current.z += delta_z;
	}
}

int			draw_points(t_size *data)
{
	int i;
	int j;

	i = 0;
	ft_bzero(data->pixel_addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	while (i < data->height)
	{
		j = 0;
		while (j < data->width - 1)
		{
			draw_line(data->points[i][j], data->points[i][j + 1], *data);
			if (i < data->height - 1)
				draw_line(data->points[i][j], data->points[i + 1][j], *data);
			j++;
		}
		if (i < data->height - 1)
			draw_line(data->points[i][j], data->points[i + 1][j], *data);
		i++;
	}
	mlx_put_image_to_window(data->init, data->window, data->image, 0, 0);
	return (1);
}
