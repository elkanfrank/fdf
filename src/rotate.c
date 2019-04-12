/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 13:19:11 by efrank         #+#    #+#                */
/*   Updated: 2019/03/20 19:28:38 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*rotate_x(t_point *points, double degrees, t_size dimensions)
{
	int		i;
	double	temp;

	i = 0;
	degrees = degrees * (PI / 180);
	while (i < dimensions.width)
	{
		points[i].x -= dimensions.width / 2;
		points[i].y -= dimensions.height / 2;
		temp = points[i].y;
		points[i].y = (points[i].y * cos(degrees)) +
		(points[i].z * sin(degrees));
		points[i].z = ((-1 * temp) * sin(degrees)) +
		(points[i].z * cos(degrees));
		points[i].x += dimensions.width / 2;
		points[i].y += dimensions.height / 2;
		i++;
	}
	return (points);
}

static t_point	*rotate_y(t_point *points, double degrees, t_size dimensions)
{
	int		i;
	double	temp;

	i = 0;
	degrees = degrees * (PI / 180);
	while (i < dimensions.width)
	{
		points[i].x -= dimensions.width / 2;
		points[i].y -= dimensions.height / 2;
		temp = points[i].x;
		points[i].x = (points[i].x * cos(degrees)) +
		(points[i].z * sin(degrees));
		points[i].z = (-temp * sin(degrees)) +
		(points[i].z * cos(degrees));
		points[i].x += dimensions.width / 2;
		points[i].y += dimensions.height / 2;
		i++;
	}
	return (points);
}

static t_point	*rotate_z(t_point *points, double degrees, t_size dimensions)
{
	int		i;
	double	temp;

	i = 0;
	degrees = degrees * (PI / 180);
	while (i < dimensions.width)
	{
		points[i].x -= dimensions.width / 2;
		points[i].y -= dimensions.height / 2;
		temp = points[i].x;
		points[i].x = (points[i].x * cos(degrees)) -
		(points[i].y * sin(degrees));
		points[i].y = (temp * sin(degrees)) +
		(points[i].y * cos(degrees));
		points[i].x += dimensions.width / 2;
		points[i].y += dimensions.height / 2;
		i++;
	}
	return (points);
}

t_point			**rotate(double degrees, t_size *data, char axis)
{
	int i;

	i = 0;
	if (axis == 'x')
		data->x_rot = (int)(data->x_rot + degrees) % 360;
	if (axis == 'y')
		data->y_rot = (int)(data->y_rot + degrees) % 360;
	if (axis == 'z')
		data->z_rot = (int)(data->z_rot + degrees) % 360;
	while (i < data->height)
	{
		if (axis == 'x')
			data->points[i] = rotate_x(data->points[i], degrees, *data);
		if (axis == 'y')
			data->points[i] = rotate_y(data->points[i], degrees, *data);
		if (axis == 'z')
			data->points[i] = rotate_z(data->points[i], degrees, *data);
		i++;
	}
	return (data->points);
}
