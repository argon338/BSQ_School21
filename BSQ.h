/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:46:14 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/23 20:46:16 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>

typedef struct s_map
{
	int		size_header;
	int		number_of_lines;
	int		line_length;
	char	empty_space;
	char	obstacle;
	char	seed;
}	t_map;

typedef struct s_point
{
	int	y;
	int	x;
}	t_point;

typedef struct s_square
{
	t_point	start;
	int		size;
}	t_square;

void		init_square(t_square *src, int y, int x, int size);
void		copy_square(t_square *dest, t_square *src);

t_square	put_bigger_square(int **map, t_point size, t_square new);
t_square	put_square(int **map, t_point size, t_square new);

t_square	check_placement(int **map, t_point size);
void		map_print(int **kek);

int			**parce_line(char *datafile, t_map map_parameters);

#endif //BSQ_H
