#include "../BSQ.h"

typedef struct s_counters
{
	int	counter;
	int	strings_counter;
	int	strings_counter_memory;
	int	quantity_of_strings;
}	t_counters;

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

int	ft_count_body_strings(const char *memory_stick, t_map *to_check,
							 t_counters county)
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