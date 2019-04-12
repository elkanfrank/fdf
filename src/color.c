/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 17:55:55 by efrank         #+#    #+#                */
/*   Updated: 2019/04/01 15:17:13 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		set_color(t_byte red, t_byte green, t_byte blue)
{
	t_color colors;

	colors.red = red;
	colors.green = green;
	colors.blue = blue;
	return (colors);
}

t_max_z		map_colors_to_height(t_size *data)
{
	int		i;
	int		j;
	t_max_z max_z;

	max_z.max = (int)data->points[0][0].z_ori;
	max_z.min = (int)data->points[0][0].z_ori;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->points[i][j].z_ori > max_z.max)
				max_z.max = (int)data->points[i][j].z_ori;
			if (data->points[i][j].z_ori < max_z.min)
				max_z.min = (int)data->points[i][j].z_ori;
			j++;
		}
		i++;
	}
	max_z.mid = (max_z.max + max_z.min) / 2;
	max_z.max_color = set_color(255, 255, 255);
	max_z.mid_color = set_color(220, 40, 40);
	max_z.min_color = set_color(11, 99, 232);
	return (max_z);
}

t_color		get_color_slope(double z, t_max_z color)
{
	if (color.min == color.max)
	{
		return (set_color(color.min_color.red,
							color.min_color.green,
							color.min_color.blue));
	}
	if (z > color.mid)
	{
		z = (z - color.mid) / (color.max - color.mid);
		z = clamp(z);
		return (set_color(color.mid_color.red * (1 - z) +
			(color.max_color.red * z),
			color.mid_color.green * (1 - z) + (color.max_color.green * z),
			color.mid_color.blue * (1 - z) + (color.max_color.blue * z)));
	}
	else
	{
		z = (z - color.min) / (color.mid - color.min);
		z = clamp(z);
		return (set_color(color.min_color.red * (1 - z) +
				(color.mid_color.red * z),
				color.min_color.green * (1 - z) + (color.mid_color.green * z),
				color.min_color.blue * (1 - z) + (color.mid_color.blue * z)));
	}
}
