#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>


typedef struct t_header
{
	int size_header;
	int size_map;
	char empty_space;
	char obstacle;
	char seed;
}	   s_header;

int	ft_strlen(char *str)
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

int ft_is_number(const char *str)
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

int ft_display_file(char **filename)
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
		//ft_putstr(": ");
		//ft_putstr(strerror(errno));
		return (-1);
	}
	size_of_file = 0;
	while (read(fp, &character, 1))
		size_of_file++;
	close(fp);

	fp = open(*filename, O_RDONLY);
	buffer = (char *) malloc(sizeof(buffer) * size_of_file);
	if (!buffer)
	{
		ft_putstr("map error / no memory located");
	}
	read(fp, buffer, size_of_file);
	
	write(1, buffer, size_of_file);

	*filename = buffer;

	close(fp);
	free(buffer);
	return (size_of_file);
}

s_header check_header(char *memory_stick)
{
	char	array_size[50];
	int	 counter;
	s_header my_header;

	counter = 0;
	if (!ft_is_digit(memory_stick[0]))
	{
		ft_putstr("oh shit no size");
		printf("%c\n", memory_stick[0]);

		my_header.size_header = -1;
		return(my_header);
	}

	while ((!ft_isspace(memory_stick[counter])) && (ft_is_digit(memory_stick[counter])))
	{
		array_size[counter] = memory_stick[counter];
		printf("add a symbol to size here: %c\n", array_size[counter]);
		counter++;
	}

	printf("total counted array size %s\n", array_size);

	if (!ft_is_printable(memory_stick[counter]))
	{
		ft_putstr("oh shit no empty symbol");
		my_header.size_header = -1;
	}
	if (!ft_is_printable(memory_stick[counter+1]))
	{
		ft_putstr("oh shit no obstacle symbol");
		my_header.size_header = -1;
	}
	if (!ft_is_printable(memory_stick[counter+2]))
	{
		ft_putstr("oh shit no body symbol");
		my_header.size_header = -1;
	}
	if (memory_stick[counter+3] != '\n')
	{
		ft_putstr("oh shit there is some trash after header");
		my_header.size_header = -1;
	}
	my_header.size_header = counter + 3;
	my_header.size_map = ft_atoi(array_size);
	my_header.empty_space = memory_stick[counter];
	my_header.obstacle = memory_stick[counter+1];
	my_header.seed = memory_stick[counter+2];

	return(my_header);
}

s_header alt_check_header(char *memory_stick)
{
	char	array_size[50];
	int	 counter;
	s_header my_header;

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
	//printf("%s строка выглядит как то так\n", array_size);

	my_header.size_header = counter - 3;

	my_header.empty_space =array_size[counter - 3];
	array_size[counter - 3] = '\0';
	my_header.obstacle = array_size[counter - 2];
	array_size[counter - 2] = '\0';
	my_header.seed = array_size[counter - 1];
	array_size[counter - 1] = '\0';

	//printf("%s строка выглядит как то так\n", array_size);

	if (!ft_strlen(array_size))
	{
		ft_putstr("oh shit no size, ничего в размере строк ");
		my_header.size_header = -1;
		return(my_header);
	}

	if (!ft_is_number(array_size))
	{
		ft_putstr("oh shit no size, мусор в размере строк");
		my_header.size_header = -1;
		return(my_header);
	}

	if (ft_atoi(array_size) < 0)
	{
		ft_putstr("пошел на хуй со своим интеджером ");
		my_header.size_header = -1;
		return(my_header);
	}

	my_header.size_map = ft_atoi(array_size);
	return(my_header);
}

int main(void)
{
	char filename[128] = "f";
	char *datafile;
	s_header my_header;


	datafile = filename; 				//	задаем имя файла
	ft_display_file(&datafile);			//	получаем содержимое файла в память
	my_header = alt_check_header(datafile);	//	получаем заголовк файла или если -1 то заголовок битый

	if (my_header.size_header < 0)
	{
		ft_putstr("map error // заголовок говно");
		return (-1);
	}
	printf("размер заголовка %i\n", my_header.size_header);
	printf("размер карты %i линий \n", my_header.size_map);
	printf("пустой символ %c\n", my_header.empty_space);
	printf("символ препятствия %c\n", my_header.obstacle);
	printf("символ заполнения квадрата %c\n", my_header.seed);
}