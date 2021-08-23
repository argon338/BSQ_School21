#ifndef BSQ_H
#define BSQ_H

typedef struct s_point
{
	int	y;
	int	x;
}	t_point;

typedef struct s_square
{
	t_point start;
	int size;
}	t_square;

void	init_square(t_square *src, int y, int x);
void	copy_square(t_square *dest, t_square *src);

t_square	put_bigger_square(int **map, int size, t_square new);
t_square	put_square(int **map, int size, t_square new);

#endif //BSQ_H
