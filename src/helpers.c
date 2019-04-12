/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 14:41:28 by efrank         #+#    #+#                */
/*   Updated: 2019/03/28 13:45:38 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_zoom(t_size *data)
{
	int surface;
	int offset;

	offset = 0.6 * (WIDTH * HEIGHT);
	surface = data->width * data->height;
	data->zoom = sqrt(((WIDTH * HEIGHT) - offset) / surface);
	data->y_rot = 0;
	data->x_rot = 0;
	data->z_rot = 0;
}

int		count_points(char *grid)
{
	int count;
	int j;

	j = 0;
	count = 0;
	if (!grid)
		return (0);
	while (grid[j])
	{
		if (j > 0 && grid[j] == ' ' && (grid[j + 1] == '-' ||
		ft_isdigit(grid[j + 1])))
			count++;
		j++;
	}
	return (count);
}

double	clamp(double z)
{
	if (z < 0)
		return (0);
	else if (z > 1)
		return (1);
	else
		return (z);
}
