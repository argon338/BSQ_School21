#include "BSQ.h"

t_square	check_placement(int **map, int size)
{
	int			i;
	int			j;
	t_square	new;
	t_square	max;

	init_square(&max, 0, 0, 0);
	i = 0;
	while (i < size - max.size + 1)
	{
		j = 0;
		while (j < size - max.size + 1)
		{
			if (!map[i][j])
			{
				init_square(&new, i, j, max.size);
				new = put_square(map, size, new);
				if (new.size > max.size)
					max = new;
			}
		}
	}
	return (max);
}