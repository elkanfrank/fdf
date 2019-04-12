/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: efrank <efrank@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/27 13:19:16 by efrank         #+#    #+#                */
/*   Updated: 2019/03/21 16:44:30 by efrank        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_chars(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	check_file(int argc, char **argv, int *fd)
{
	char	*line;
	int		char_width;

	if (argc != 2)
		return (0);
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
		return (-1);
	get_next_line(*fd, &line);
	char_width = count_points(line);
	free(line);
	if (!char_width)
		return (-1);
	while (get_next_line(*fd, &line))
	{
		if (count_points(line) != char_width)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	close(*fd);
	return (1);
}

static int	*get_nums(char *line, t_size *dimensions)
{
	char	**split;
	int		i;
	int		*nums;

	i = 0;
	dimensions->width = 0;
	split = ft_strsplit(line, ' ');
	while (split[dimensions->width])
		dimensions->width++;
	nums = (int *)malloc(sizeof(int) * dimensions->width);
	while (i < dimensions->width)
	{
		nums[i] = ft_atoi(split[i]);
		i++;
	}
	ft_free_arrays((void **)split);
	return (nums);
}

static int	**store_input(char **argv, int fd, t_size *dimensions)
{
	int		**grid;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	dimensions->height = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		dimensions->height++;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	grid = (int **)malloc(sizeof(int *) * dimensions->height + 1);
	while (get_next_line(fd, &line))
	{
		grid[i] = get_nums(line, dimensions);
		free(line);
		i++;
	}
	close(fd);
	grid[i] = NULL;
	return (grid);
}

t_point		**get_input(int argc, char **argv, t_size *dimensions)
{
	int		**grid;
	int		fd;
	t_point	**points;

	if (!check_file(argc, argv, &fd))
	{
		ft_putstr("usage: ./fdf [ map file ]\n");
		exit(1);
	}
	else if (check_file(argc, argv, &fd) == -1)
	{
		ft_putstr("Invalid file\n");
		exit(1);
	}
	grid = store_input(argv, fd, dimensions);
	points = convert_to_points(grid, *dimensions);
	dimensions->backup = convert_to_points(grid, *dimensions);
	ft_free_arrays((void**)grid);
	return (points);
}
