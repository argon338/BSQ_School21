/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:03:59 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/24 15:04:01 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BSQ.h"
#include <stdlib.h>

void	free_array(int **a, int i)
{
	while (i >= 0)
	{
		free(a[i]);
		i--;
	}
	free(a);
}

int	find_reference(char symbol, t_map map_parameters)
{
	if (symbol == map_parameters.empty_space)
		return (0);
	if (symbol == map_parameters.obstacle)
		return (1);
	else
		return (-1);
}

int	**fill_map(char *datafile, t_map map_parameters, int **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < map_parameters.number_of_lines)
	{
		map[i] = (int *)malloc(sizeof(int) * map_parameters.line_length);
		if (map[i] == NULL)
		{
			free_array(map, i - 1);
			return (NULL);
		}
		j = 0;
		while (j < map_parameters.line_length)
		{
			map[i][j] = find_reference(datafile[k], map_parameters);
			k++;
			j++;
		}
		i++;
		k++;
	}
	return (map);
}

int	**parce_line(char *datafile, t_map map_parameters)
{
	int	**map;

	datafile += map_parameters.size_header + 1;
	map = (int **)malloc(sizeof(int *) * map_parameters.number_of_lines);
	if (!map)
		return (NULL);
	return (fill_map(datafile, map_parameters, map));
}
