/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 15:15:27 by efrank         #+#    #+#                */
/*   Updated: 2019/03/26 15:24:47 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**convert_to_points(int **grid, t_size dimensions)
{
	int		i;
	int		j;
	int		point_count;
	t_point	**points;

	point_count = dimensions.width * dimensions.height;
	points = malloc(sizeof(t_point) * dimensions.height);
	i = 0;
	while (i < dimensions.height)
	{
		j = 0;
		points[i] = malloc(sizeof(t_point) * dimensions.width);
		while (j < dimensions.width)
		{
			points[i][j].x = j;
			points[i][j].y = i;
			points[i][j].z = grid[i][j] * -1;
			points[i][j].z_ori = grid[i][j];
			j++;
		}
		i++;
	}
	return (points);
}
