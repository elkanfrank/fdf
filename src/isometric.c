/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isometric.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 16:08:33 by efrank         #+#    #+#                */
/*   Updated: 2019/03/27 18:09:15 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_size *data)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		ft_memcpy(data->points[i], data->backup[i],
		data->width * sizeof(t_point));
		i++;
	}
	data->x_rot = 0;
	data->y_rot = 0;
	data->z_rot = 0;
	while (data->x_rot != 30)
		rotate(1, data, 'x');
	while (data->z_rot != 30)
		rotate(1, data, 'z');
	while (data->y_rot != 30)
		rotate(1, data, 'y');
}

void	change_height(int amount, t_size *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->points[i][j].z_ori != 0)
				data->points[i][j].z += amount;
			j++;
		}
		i++;
	}
}
