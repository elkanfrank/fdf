/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   control.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 15:11:06 by efrank         #+#    #+#                */
/*   Updated: 2019/03/27 17:58:28 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_key(int key, t_size *data)
{
	if (key == 53)
		exit(1);
	if (key == 126)
		rotate(2, data, 'x');
	if (key == 125)
		rotate(-2, data, 'x');
	if (key == 123)
		rotate(2, data, 'y');
	if (key == 124)
		rotate(-2, data, 'y');
	if (key == 13)
		data->zoom += 0.05 * data->zoom;
	else if (key == 1)
		data->zoom -= 0.05 * data->zoom;
	if (key == 49)
		isometric(data);
	if (key == 31)
		change_height(1, data);
	else if (key == 37)
		change_height(-1, data);
	return (0);
}
