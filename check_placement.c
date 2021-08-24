/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:46:02 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/23 20:46:04 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"
#include <stdio.h>
t_square	check_placement_zero(int **map, t_point size)
{
	t_point		cursor;
	t_square	new;
	t_square	max;

	init_square(&max, 0, 0, 0);
	cursor.y = 0;
	while (cursor.y < size.y - max.size)
	{
		cursor.x = 0;
		while (cursor.x < size.x - max.size)
		{
			//printf("put_square cursor (%d, %d)\n", cursor.y, cursor.x);
			if (map[cursor.y][cursor.x] == 0)
			{
				init_square(&new, cursor.y, cursor.x, max.size);
				new = put_square(map, size, new);
				if (new.size > max.size)
				{
					max = new;
					return (max);
				}
			}
			cursor.x++;
		}
		cursor.y++;
	}
	return (max);
}

t_square	check_placement(int **map, t_point size)
{
	t_point		cursor;
	t_square	new;
	t_square	max;

	max = check_placement_zero(map, size);
	if (max.size)
	{
		cursor.y = 0;
		while ((cursor.y < size.y - max.size + 1) && (max.size < size.x)) {
			cursor.x = 0;
			while ((cursor.x < size.x - max.size + 1) && (max.size < size.y)) {
				printf("put_square cursor (%d, %d)\n", cursor.y, cursor.x);
				if (map[cursor.y][cursor.x] == 0) {
					init_square(&new, cursor.y, cursor.x, max.size);
					new = put_square(map, size, new);
					if (new.size > max.size)
						max = new;
				}
				cursor.x++;
			}
			cursor.y++;
		}
	}
	return (max);
}
