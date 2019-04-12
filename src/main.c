/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/15 18:04:59 by efrank         #+#    #+#                */
/*   Updated: 2019/03/28 13:39:14 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_size data;

	data.points = get_input(argc, argv, &data);
	data.init = mlx_init();
	data.window = mlx_new_window(data.init, WIDTH, HEIGHT, "fdf");
	data.image = mlx_new_image(data.init, WIDTH, HEIGHT);
	data.max_z = map_colors_to_height(&data);
	set_zoom(&data);
	data.pixel_addr = mlx_get_data_addr(data.image, &(data.bits_per_pixel),
	&(data.line_size), &(data.endian));
	mlx_hook(data.window, 2, 1L << 2, &get_key, &data);
	mlx_loop_hook(data.init, &draw_points, &data);
	mlx_loop(data.init);
	return (0);
}
