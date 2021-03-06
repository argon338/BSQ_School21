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

#include "../BSQ.h"

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
			if (map[cursor.y][cursor.x] == 0)
			{
				init_square(&new, cursor.y, cursor.x, max.size);
				new = put_square(map, size, new);
				if (new.size > max.size)
				{
					return (new);
				}
			}
			cursor.x++;
		}
		cursor.y++;
	}
	return (max);
}

void	cmp_square(t_square *max, t_square *new)
{
	if (new->size > max->size)
		*max = *new;
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
		while ((cursor.y < size.y - max.size) && (max.size < size.x))
		{
			cursor.x = 0;
			while ((cursor.x < size.x - max.size) && (max.size < size.y))
			{
				if (map[cursor.y][cursor.x] == 0)
				{
					init_square(&new, cursor.y, cursor.x, max.size + 1);
					new = put_square(map, size, new);
					cmp_square(&max, &new);
				}
				cursor.x++;
			}
			cursor.y++;
		}
	}
	return (max);
}
