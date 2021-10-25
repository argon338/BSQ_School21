/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:35:03 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:35:05 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "BSQ.h"
#include <unistd.h>

int	find_the_square(int **map, t_map map_par)
{
	t_point		map_size;
	t_square	max_square;

	map_size.y = map_par.number_of_lines;
	map_size.x = map_par.line_length;
	max_square = check_placement(map, map_size);
	map_print_sqr(map, map_par, max_square);
	free_array(map, map_par.number_of_lines - 1);
	return (0);
}

int	data_file_to_map(char *data_file)
{
	t_map	map_par;
	int		**map;

	if (parce_from_data_file(data_file, &map_par))
	{
		if (data_file != NULL)
			free(data_file);
		write(2, "map error\n", 11);
		return (1);
	}
	map = parce_line(data_file, map_par);
	free(data_file);
	if (map == NULL)
	{
		write(2, "map error\n", 11);
		return (1);
	}
	return (find_the_square(map, map_par));
}

int	accept_stdin(void)
{
	char	*data_file;

	data_file = stdin_to_string();
	if (data_file == NULL)
	{
		write(2, "map error\n", 11);
		return (1);
	}
	return (data_file_to_map(data_file));
}

int	accept_file(char *data_file)
{
	int	readerr;

	readerr = ft_display_file(&data_file);
	if (readerr <= 0)
	{
		write(2, "map error\n", 11);
		return (1);
	}
	if (data_file == NULL)
	{
		write(2, "map error\n", 11);
		return (1);
	}
	return (data_file_to_map(data_file));
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (accept_stdin());
	i = 1;
	while (i < argc)
	{
		accept_file(argv[i]);
		i++;
	}
	return (0);
}
