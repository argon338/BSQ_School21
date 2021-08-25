/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:38:49 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:38:50 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BSQ.h"
#include <stdlib.h>

int	ft_is_header_symbols_okay(char *array_size, int counter)
{
	if (!ft_is_printable(array_size[counter - 3]))
		return (0);
	if (!ft_is_printable(array_size[counter - 2]))
		return (0);
	if (!ft_is_printable(array_size[counter - 1]))
		return (0);
	else
		return (1);
}

int	ft_has_header_duplicates(t_map my_header)
{
	if ((my_header.empty_space == my_header.obstacle)
		|| (my_header.obstacle == my_header.seed)
		|| (my_header.seed == my_header.empty_space))
		return (1);
	else
		return (0);
}

char	*ft_fill_header(char *memory_stick, int *counter)
{
	int		mem_size;
	char	*array_size;

	mem_size = 4;
	array_size = (char *) malloc(sizeof(char) * mem_size);
	if (array_size == NULL)
		return (NULL);
	ft_empty_string(array_size, mem_size);
	*counter = -1;
	while (!ft_isspace(memory_stick[++(*counter)]))
	{
		array_size = ft_char_push_back(array_size,
				memory_stick[(*counter)], &mem_size);
		if (array_size == NULL)
			return (NULL);
	}
	return (array_size);
}

t_map	ft_header_error_processing(char *array_size, t_map my_header)
{
	if (!ft_strlen(array_size))
		my_header.size_header = -1;
	if ((ft_strlen(array_size) == 1) && (array_size[0] == '0'))
		my_header.size_header = -1;
	if (!ft_is_number(array_size))
		my_header.size_header = -1;
	if (ft_atoi(array_size) < 0)
		my_header.size_header = -1;
	my_header.number_of_lines = ft_atoi(array_size);
	if (array_size != NULL)
		free(array_size);
	return (my_header);
}

t_map	ft_check_header(char *memory_stick)
{
	char	*array_size;
	int		counter;
	t_map	my_header;

	array_size = ft_fill_header(memory_stick, &counter);
	if (array_size == NULL)
	{
		my_header.size_header = -1;
		return (my_header);
	}
	my_header.size_header = counter;
	if (!ft_is_header_symbols_okay(array_size, counter))
		my_header.size_header = -1;
	my_header.empty_space = array_size[counter - 3];
	array_size[counter - 3] = '\0';
	my_header.obstacle = array_size[counter - 2];
	array_size[counter - 2] = '\0';
	my_header.seed = array_size[counter - 1];
	array_size[counter - 1] = '\0';
	if (ft_has_header_duplicates(my_header))
		my_header.size_header = -1;
	return (ft_header_error_processing(array_size, my_header));
}
