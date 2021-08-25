/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:55:29 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:55:30 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_STRUCT_H
# define CUSTOM_STRUCT_H

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

#endif //CUSTOM_STRUCT_H
