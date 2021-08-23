/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:46:23 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/23 20:46:25 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	init_square(t_square *src, int y, int x, int size)
{
	src->size = size;
	src->start.x = x;
	src->start.y = y;
}

void	copy_square(t_square *dest, t_square *src)
{
	dest->size = src->size;
	dest->start.x = src->start.x;
	dest->start.y = src->start.y;
}
