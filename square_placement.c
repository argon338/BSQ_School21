#include "BSQ.h"

t_square	mark_inaccessible(int **map, t_point size, t_square new, t_point obstacle)
{
#ifdef TEST
	(void)map;
	(void)size;
	(void)obstacle;
#endif
#ifndef TEST
	//printf("Obstacle (%d, %d)\n", obstacle.y, obstacle.x);
	t_point cursor;
	cursor.y = new.start.y;
	while (cursor.y <= obstacle.y && cursor.y < size.y)
	{
		cursor.x = new.start.x;
		while (cursor.x <= obstacle.x && cursor.x < size.x)
		{
			if (!map[cursor.y][cursor.x])
				map[cursor.y][cursor.x] = 2;
			cursor.x++;
		}
		cursor.y++;
	}
#endif
	new.size--;
	return (new);
}

t_square	call_bigger_square(int **map, t_point size, t_square new)
{
	new.size++;
	return (put_bigger_square(map, size, new));
}

t_square	put_bigger_square(int **map, t_point size, t_square new)
{
	t_point cursor;
	int	success;

	cursor.y = new.start.y;
	cursor.x = new.start.x + new.size - 1;
	success = 1;
	while (cursor.y < new.start.y + new.size && success)
	{
		//printf("put_bigger_square cursor (%d, %d) ----  ", cursor.y, cursor.x);
		if (cursor.y >= size.y)
			success = 0;
		else if (map[cursor.y][cursor.x])
			success = 0;
		cursor.y++;
	}
	if (!success)
	{
		cursor.y--;
		//printf("Cursor on obstacle (%d, %d)\n", cursor.y, cursor.x);
		return (mark_inaccessible(map, size, new, cursor));
	}
	cursor.y = new.start.y + new.size - 1;
	cursor.x = new.start.x;
	while (cursor.x < new.start.x + new.size - 1 && success)
	{
		//printf("put_bigger_square cursor (%d, %d) ----  ", cursor.y, cursor.x);
		if (cursor.x >= size.x)
			success = 0;
		else if (map[cursor.y][cursor.x])
			success = 0;
		cursor.x++;
	}
	//printf("\n");
	if (success)
		return (call_bigger_square(map, size, new));
	else
	{
		cursor.x--;
		//printf("Cursor on obstacle (%d, %d)\n", cursor.y, cursor.x);
		return (mark_inaccessible(map, size, new, cursor));
	}
}

t_square	put_square(int **map, t_point size, t_square new)
{
	t_point cursor;
	int	success;
	
	cursor.y = new.start.y;
	success = 1;
	while (cursor.y < new.start.y + new.size && success)
	{
		cursor.x = new.start.x;
		while (cursor.x < new.start.x + new.size && success)
		{
			//printf("put_square cursor (%d, %d) ----  ", cursor.y, cursor.x);
			if (cursor.y >= size.y || cursor.x >= size.x)
				success = 0;
			else if (map[cursor.y][cursor.x])
				success = 0;
			cursor.x++;
		}
		cursor.y++;
	}
	//printf("\n");
	if (success)
	{
		new.size++;
		return (put_bigger_square(map, size, new));
	}
	else
	{
		cursor.y--;
		cursor.x--;
		return (mark_inaccessible(map, size, new, cursor));
	}
}