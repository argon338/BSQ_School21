#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include "custom_string.h"

typedef struct s_map
{
	int		size_header;
	int		number_of_lines;
	int		line_length;
	char	empty_space;
	char	obstacle;
	char	seed;
}	t_map;

typedef struct s_counters
{
	int	counter;
	int	strings_counter;
	int	strings_counter_memory;
	int	quantity_of_strings;
}	t_counters;

int	ft_atoi(char *str)
{
	int		i;
	int		mult;
	int		nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

int	ft_isspace(int c)
{
	if (c == '\0' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_digit(int c)
{
	if (c == '1' || c == '2' || c == '3'
		|| c == '4' || c == '5' || c == '6'
		|| c == '7' || c == '8' || c == '9'
		|| c == '0')
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_is_number(const char *str)
{
	int	counter;

	counter = 0;
	while (!ft_isspace(str[counter]))
	{
		if (!ft_is_digit(str[counter]))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}

int	ft_is_printable(char c)
{
	if ((c >= 32 && c <= 126) || (c == '\n'))
		return (1);
	return (0);
}

void	ft_putstr(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		write(1, &str[counter++], 1);
}

int	ft_display_file(char **filename)
{
	char	character;
	int		fp;
	char	*buffer;
	int		size_of_file;

	fp = open(*filename, O_RDONLY);
	if (fp == -1)
		return (-1);
	size_of_file = 0;
	while (read(fp, &character, 1))
		size_of_file++;
	close(fp);
	fp = open(*filename, O_RDONLY);
	buffer = (char *) malloc(sizeof(buffer) * (size_of_file + 1));
	if (!buffer)
		return (-1);
	read(fp, buffer, size_of_file);
	buffer[size_of_file] = '\0';
	write(1, buffer, size_of_file);
	*filename = buffer;
	close(fp);
	return (size_of_file);
}

int	ft_is_header_symbols_okay(char *memory_stick)
{
	char	array_size[50];
	int		counter;

	counter = 0;
	while (!ft_isspace(memory_stick[counter]))
	{
		array_size[counter] = memory_stick[counter];
		counter++;
	}
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
	free(array_size);
	return (my_header);
}

t_map	ft_check_header(char *memory_stick)
{
	char	*array_size;
	int		counter;
	t_map	my_header;
	//printf("^%s^", memory_stick);

	array_size = ft_fill_header(memory_stick, &counter);
	printf("\n^^%s^^\n", array_size);
	if (array_size == NULL)
	{
		//printf("here\n");
		my_header.size_header = -1;
		return (my_header);
	}
	my_header.size_header = counter;
	if (!ft_is_header_symbols_okay(memory_stick))
		my_header.size_header = -1;
	my_header.empty_space = array_size[counter - 3];
	array_size[counter - 3] = '\0';
	my_header.obstacle = array_size[counter - 2];
	array_size[counter - 2] = '\0';
	my_header.seed = array_size[counter - 1];
	array_size[counter - 1] = '\0';
	if (ft_has_header_duplicates(my_header))
		my_header.size_header = -1;
	printf(">>> %d <<<\n", my_header.size_header);
	printf("^^%s^^\n", array_size);
	return (ft_header_error_processing(array_size, my_header));
}

int	check_map_body_symbols(const char *memory_stick, t_map to_check)
{
	int	counter;

	counter = to_check.size_header + 1;
	while (memory_stick[counter])
	{
		if (((memory_stick[counter] != to_check.empty_space)
				&& (memory_stick[counter] != to_check.obstacle)
				&& (memory_stick[counter] != '\n')
				&& (memory_stick[counter] != '\0'))
			|| (memory_stick[counter] == to_check.seed))
		{
			return (-counter);
		}
		counter++;
	}
	return (0);
}

int	ft_count_body_strings(const char *memory_stick,
							 t_map *to_check, t_counters county)
{
	while (memory_stick[county.counter])
	{
		while ((memory_stick[county.counter] != '\n'))
		{
			if (memory_stick[county.counter] == '\0')
				return (-county.counter);
			county.strings_counter++;
			county.counter++;
		}
		county.counter++;
		if (county.strings_counter_memory == county.strings_counter)
			county.strings_counter = 0;
		else
			return (-county.counter);
		county.quantity_of_strings++;
	}
	if (county.quantity_of_strings != (*to_check).number_of_lines)
		return (-county.counter);
	to_check->line_length = county.strings_counter_memory;
	return (0);
}

int	check_map_body_strings(const char *memory_stick, t_map *to_check)
{
	t_counters	county;

	county.strings_counter = 0;
	county.strings_counter_memory = 0;
	county.counter = (*to_check).size_header + 1;
	county.quantity_of_strings = 0;
	while (memory_stick[county.counter])
	{
		if (!memory_stick[county.counter])
			return (-1);
		while (memory_stick[county.counter] != '\n')
		{
			if (memory_stick[county.counter] == '\0')
				return (-county.counter);
			county.counter++;
			county.strings_counter_memory++;
		}
		county.quantity_of_strings++;
		break ;
	}
	county.counter++;
	return (ft_count_body_strings(memory_stick, to_check, county));
}

char	*stdin_to_string(void);

int	main_parcer(char **datafile, t_map *my_header)
{
	char filename[128] = "f";


	*datafile = filename;
										 //	задаем имя файла
	ft_display_file(datafile);				//	получаем содержимое файла в память
	//*datafile = stdin_to_string();
	*my_header = ft_check_header(*datafile);	//	получаем заголовк файла или если -1 то заголовок битый

	if (my_header->size_header < 0)
	{
		ft_putstr("map error // заголовок говно");
		return (-1);
	}
//	printf("размер заголовка %i\n", my_header->size_header);
//	printf("размер карты %i линий \n", my_header->number_of_lines);
//	printf("пустой символ %c\n", my_header->empty_space);
//	printf("символ препятствия %c\n", my_header->obstacle);
//	printf("символ заполнения квадрата %c\n", my_header->seed);
//	printf("размер строки ёба %d\n", my_header->line_length);
	printf("     %d\n", check_map_body_symbols(*datafile, *my_header));
	printf("     %d\n", check_map_body_strings(*datafile, my_header));
//	printf("размер строки ёба %d\n", my_header->line_length);
	return(0);

}
