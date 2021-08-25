/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_placement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:46:32 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/23 20:46:34 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BSQ.h"
#include <stdio.h>
t_square	mark_inaccessible(int **map, t_point size, t_square new,
							  t_point obstacle)
{
	t_point	cursor;

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
	new.size--;
	return (new);
}

t_square	put_bigger_square_part_2(int **map, t_point size, t_square new)
{
	t_point	cursor;
	int		success;

	cursor.y = new.start.y + new.size - 1;
	cursor.x = new.start.x;
	success = 1;
	while (cursor.x < new.start.x + new.size - 1 && success)
	{
		if (cursor.y >= size.y || cursor.x >= size.x)
			success = 0;
		else if (map[cursor.y][cursor.x] == 1)
			success = 0;
		cursor.x++;
	}
	if (success)
	{
		new.size++;
		return (put_bigger_square(map, size, new));
	}
	else
	{
		cursor.x--;
		return (mark_inaccessible(map, size, new, cursor));
	}
}

t_square	put_bigger_square(int **map, t_point size, t_square new)
{
	t_point	cursor;
	int		success;

	cursor.y = new.start.y;
	cursor.x = new.start.x + new.size - 1;
	success = 1;
	while ((cursor.y < new.start.y + new.size) && success)
	{
		if (cursor.y >= size.y || cursor.x >= size.x)
			success = 0;
		else if (map[cursor.y][cursor.x] == 1)
			success = 0;
		cursor.y++;
	}
	if (!success)
	{
		cursor.y--;
		return (mark_inaccessible(map, size, new, cursor));
	}
	else
		return (put_bigger_square_part_2(map, size, new));
}

t_square	call_mark_inaccessible(int **map, t_point size, t_square new,
								   t_point cursor)
{
	cursor.y--;
	cursor.x--;
	return (mark_inaccessible(map, size, new, cursor));
}

t_square	put_square(int **map, t_point size, t_square new)
{
	t_point	cursor;
	int		success;

	cursor.y = new.start.y;
	success = 1;
	while (cursor.y < new.start.y + new.size && success)
	{
		cursor.x = new.start.x;
		while (cursor.x < new.start.x + new.size && success)
		{
			if (cursor.y >= size.y || cursor.x >= size.x)
				success = 0;
			else if (map[cursor.y][cursor.x] == 1)
				success = 0;
			cursor.x++;
		}
		cursor.y++;
	}
	if (success)
	{
		new.size++;
		return (put_bigger_square(map, size, new));
	}
	else
		return (call_mark_inaccessible(map, size, new, cursor));
}
