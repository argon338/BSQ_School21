#include "../BSQ.h"
#include <unistd.h>

void	find_symbol(int symbol, t_map map_par)
{
	if (symbol == 1)
		write(1, &map_par.obstacle, 1);
	else if (symbol == 3)
		write(1, &map_par.seed, 1);
	else
		write(1, &map_par.empty_space, 1);
}

void	map_print_sqr(int **map, t_map map_par, t_square max)
{
	t_point	cursor;

	cursor.y = max.start.y;
	while (cursor.y < max.start.y + max.size)
	{
		cursor.x = max.start.x;
		while (cursor.x < max.start.x + max.size)
		{
			map[cursor.y][cursor.x] = 3;
			cursor.x++;
		}
		cursor.y++;
	}
	cursor.y = 0;
	while (cursor.y < map_par.number_of_lines)
	{
		cursor.x = 0;
		while (cursor.x < map_par.line_length)
		{
			find_symbol(map[cursor.y][cursor.x], map_par);
			cursor.x++;
		}
		write(1, "\n", 1);
		cursor.y++;
	}
}