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

t_square	check_placement(int **map, t_point size)
{
	t_point		cursor;
	t_square	new;
	t_square	max;

	init_square(&max, 0, 0, 0);
	cursor.y = 0;
	while (cursor.y < size.y - max.size + 1)
	{
		cursor.x = 0;
		while (cursor.x < size.x - max.size + 1)
		{
			if (!map[cursor.y][cursor.x])
			{
				init_square(&new, cursor.y, cursor.x, max.size);
				new = put_square(map, size, new);
				if (new.size > max.size)
					max = new;
			}
			cursor.x++;
		}
		cursor.y++;
	}
	return (max);
}
