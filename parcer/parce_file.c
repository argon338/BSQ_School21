/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:40:33 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:40:35 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../BSQ.h"

int	ft_display_file(char **filename)
{
	char	character;
	int		fp;
	char	*buffer;
	int		size_of_file;

	fp = open(*filename, O_RDONLY);
	if (fp == -1)
	{
		return (-1);
	}
	size_of_file = 0;
	while (read(fp, &character, 1))
		size_of_file++;
	close(fp);
	fp = open(*filename, O_RDONLY);
	buffer = (char *) malloc(sizeof(buffer) * (size_of_file + 1));
	if (!buffer)
		return (-1);
	if (read(fp, buffer, size_of_file) < 0)
		return (-1);
	buffer[size_of_file] = '\0';
	*filename = buffer;
	close(fp);
	return (size_of_file);
}

int	parce_from_data_file(char *datafile, t_map *my_header)
{
	int	read_error;

	*my_header = ft_check_header(datafile);
	if (my_header->size_header < 0)
		return (-1);
	read_error = check_map_body_symbols(datafile, *my_header);
	if (read_error)
		return (read_error);
	read_error = check_map_body_strings(datafile, my_header);
	if (read_error != 0)
		return (read_error);
	return (0);
}
