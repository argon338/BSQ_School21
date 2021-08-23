#include "BSQ.h"

t_square	mark_inaccessible(int **map, t_square new, int	obstacle_x, int	obstacle_y)
{
	int			i;
	int 		j;

	i = 0;
	while (new.start.y + i <= obstacle_y)
	{
		j = 0;
		while (new.start.x + j <= obstacle_x)
		{
			if (!map[new.start.y + i][new.start.x + j])
				map[new.start.y + i][new.start.x + j] = 2;
		}
	}
	new.size--;
	return (new);
}

t_square	call_bigger_square(int **map, int size, t_square new)
{
	new.size++;
	return (put_bigger_square(map, size, new));
}

t_square	put_bigger_square(int **map, int size, t_square new)
{
	int	i;
	int	success;

	i = 0;
	success = 1;
	while (i < new.size && success)
	{
		if (new.start.y + i >= size)
			success = 0;
		if (map[new.start.y + i][new.start.x + new.size - 1] && success)
			success = 0;
	}
	if (success)
		i = 0;
	while (i < new.size && success)
	{
		if (new.start.x + i >= size)
			success = 0;
		if (map[new.start.x + new.size - 1][new.start.x + i] && success)
			success = 0;
	}
	if (success)
		return (call_bigger_square(map, size, new));
	else
		return (mark_inaccessible(map, new, i, j));
}

t_square	put_square(int **map, int size, t_square new)
{
	int	i;
	int	j;
	int	success;
	
	i = 0;
	success = 1;
	while (i < new.size && success)
	{
		j = 0;
		while (j < new.size && success)
		{
			if (new.start.y + i >= size || new.start.x + j >= size)
				success = 0;
			if (map[new.start.y + i][new.start.x + j] && success)
				success = 0;
		}
	}
	if (success)
	{
		new.size++;
		return (put_bigger_square(map, size, new));
	}
	else
		return (mark_inaccessible(map, new, i, j));
}