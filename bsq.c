#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>


typedef struct s_map
{
	int		size_header;
	int		number_of_lines;
	int		line_length;
	char	empty_space;
	char	obstacle;
	char	seed;
}  t_map;

int		ft_strlen(char *str)
{
	int	ln;

	ln = 0;
	while (str[ln] != '\0')
	{
		ln++;
	}
	return (ln);
}

int		ft_atoi(char *str)
{
	int		i;
	int		mult;
	int		nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
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

int		ft_isspace(int c)
{
	return (c == '\0' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

int		ft_is_digit(int c)
{
	return (c == '1' || c == '2' || c == '3' ||
			c == '4' || c == '5' || c == '6' ||
			c == '7' || c == '8' || c == '9' ||
						c == '0' ? 1 : 0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_is_number(const char *str)
{
	int counter;

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

int		ft_is_printable(char c)
{
	if ((c >= 32 && c <= 126) || (c == '\n'))
		return (1);
	return (0);
}

void	ft_putstr(const char *str)
{
	int counter = 0;
	while (str[counter])
		write(1, &str[counter++],1);
}

int 	ft_display_file(char **filename)
{
	char	character;
	int		fp;
	char	*buffer;
	int		size_of_file;

	fp = open(*filename, O_RDONLY);
	if (fp == -1)
	{
		ft_putstr("map error // can't open");
		ft_putstr(basename(*filename));
		return (-1);
	}
	size_of_file = 0;
	while (read(fp, &character, 1))
		size_of_file++;
	close(fp);

	fp = open(*filename, O_RDONLY);
	buffer = (char *) malloc(sizeof(buffer) * size_of_file + 1);
	if (!buffer)
	{
		ft_putstr("map error / no memory located");
		return (-1);
	}
	read(fp, buffer, size_of_file);
	buffer[size_of_file + 1] = '\0';

	write(1, buffer, size_of_file);		// показываем чего там начитали

	*filename = buffer;

	close(fp);
	free(buffer);
	return (size_of_file);
}

t_map ft_check_header(char *memory_stick)
{
	char	array_size[50];
	int	 counter;
	t_map my_header;

	counter = 0;
	while (!ft_isspace(memory_stick[counter]))			// читаем строку с заголовком
	{
		array_size[counter] = memory_stick[counter];
		counter++;
	}
	if (!ft_is_printable(array_size[counter-3])) 	//проверяем символ пустоты
	{
		ft_putstr("oh shit no empty symbol ");
		my_header.size_header = -1;
	}
	if (!ft_is_printable(array_size[counter-2]))		//проверяем символ препятствия
	{
		ft_putstr("oh shit no obstacle symbol ");
		my_header.size_header = -1;
	}
	if (!ft_is_printable(array_size[counter-1]))		//проверяем символ тела квадрата
	{
		ft_putstr("oh shit no body symbol ");
		my_header.size_header = -1;
	}

	my_header.size_header = counter;
	my_header.empty_space =array_size[counter - 3];
	array_size[counter - 3] = '\0';
	my_header.obstacle = array_size[counter - 2];
	array_size[counter - 2] = '\0';
	my_header.seed = array_size[counter - 1];
	array_size[counter - 1] = '\0';

	if ((my_header.empty_space == my_header.obstacle)
	|| (my_header.obstacle == my_header.seed)
	|| (my_header.seed == my_header.empty_space))
	{
		ft_putstr("oh shit no size, есть одинаковые символы\n");
		my_header.size_header = -1;
		return(my_header);
	}

	if (!ft_strlen(array_size))
	{
		ft_putstr("oh shit no size, ничего в размере строк\n");
		my_header.size_header = -1;
		return(my_header);
	}

	if ((ft_strlen(array_size) == 1) && (array_size[0] == '0'))
	{
		ft_putstr("oh shit no size, нулевой размер бро\n");
		my_header.size_header = -1;
		return(my_header);
	}

	if (!ft_is_number(array_size))
	{
		ft_putstr("oh shit no size, мусор в размере строк\n");
		my_header.size_header = -1;
		return(my_header);
	}

	if (ft_atoi(array_size) < 0)
	{
		ft_putstr("пошел на хуй со своим интеджером\n");
		my_header.size_header = -1;
		return(my_header);
	}

	my_header.number_of_lines = ft_atoi(array_size);
	return(my_header);
}		//	в релиз ^_^

int		check_map_body_symbols(const char *memory_stick, t_map to_check)
{
	int counter;

	counter = to_check.size_header + 1;
	while (memory_stick[counter])
	{
		if (
			(memory_stick[counter] != to_check.empty_space) &&
			(memory_stick[counter] != to_check.obstacle)	&&
			(memory_stick[counter] == to_check.seed)	&&
			(memory_stick[counter] != '\n')	&&
			(memory_stick[counter] != '\0')
			)
		{
			printf("Дичь на карте ёк макарёк!! %c ==", memory_stick[counter]);
			printf("== %c, %c, %c", to_check.empty_space, to_check.obstacle, to_check.seed);
			return (-counter);
		}
		counter++;
	}
	return (0);
}

int		check_map_body_strings(const char *memory_stick, t_map to_check)
{
	int counter;
	int strings_counter;
	int strings_counter_memory;

	strings_counter = 0;
	strings_counter_memory = 0;
	counter = to_check.size_header + 1;
	while (memory_stick[counter])
	{
		if (memory_stick[counter] == '\0')		//	проверка на неожиданный конец файла
		{
			printf("неожиданный конец файла");
			return (-1);
		}
		if (memory_stick[counter] != '\n')		//	вычисляем длинну первой строки
		{
			counter++;
			break;
		}
		strings_counter_memory++;
		counter++;
	}

	while (memory_stick[counter])
		while (memory_stick[counter])
		{
			if ((memory_stick[counter] != '\n'))
			{
				if (strings_counter_memory == strings_counter)
				{	//ok
					strings_counter = 0;
				}
				else
				{	//not ok
					printf("строка не равна бро\n");
					strings_counter = 0;
				}
			}
			counter++;
		}
	return (0);
}


int		main(void)
{
	char filename[128] = "f";
	char *datafile;
	t_map my_header;


	datafile = filename;
										 //	задаем имя файла
	ft_display_file(&datafile);				//	получаем содержимое файла в память
	my_header = ft_check_header(datafile);	//	получаем заголовк файла или если -1 то заголовок битый

	if (my_header.size_header < 0)
	{
		ft_putstr("map error // заголовок говно");
		return (-1);
	}
	printf("размер заголовка %i\n", my_header.size_header);
	printf("размер карты %i линий \n", my_header.number_of_lines);
	printf("пустой символ %c\n", my_header.empty_space);
	printf("символ препятствия %c\n", my_header.obstacle);
	printf("символ заполнения квадрата %c\n", my_header.seed);

	printf("     %d", check_map_body_symbols(datafile, my_header));
	printf("     %d", check_map_body_strings(datafile, my_header));

}