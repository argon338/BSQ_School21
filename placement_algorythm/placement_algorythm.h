/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_algorythm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:50:11 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:50:13 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACEMENT_ALGORYTHM_H
# define PLACEMENT_ALGORYTHM_H

# include "../BSQ.h"
//Defined in misc.c
void		init_square(t_square *src, int y, int x, int size);
//Defined in square_placement.c
t_square	put_bigger_square(int **map, t_point size, t_square new);
t_square	put_square(int **map, t_point size, t_square new);
//Defined in check_placement.c
t_square	check_placement(int **map, t_point size);

#endif //PLACEMENT_ALGORYTHM_H
