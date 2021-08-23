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