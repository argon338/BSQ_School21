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

# include "custom_string/custom_string.h"
# include "parcer/parcer.h"
# include "placement_algorythm/placement_algorythm.h"
# include "map_print/map_print.h"

#endif //BSQ_H
