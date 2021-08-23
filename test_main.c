#include <stdio.h>
#include <stdlib.h>
#include "BSQ.h"

void ft_copy (int **dest, int src[9][27])
{
	for (int i = 0; i < 9; i++)
	{
		dest[i] = (int *)malloc(sizeof(int)*27);
		for (int j = 0; j < 27; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

void map_print(int **kek)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			if (kek[i][j] == 1)
				printf("o");
			else if (kek[i][j] == 2)
				printf("x");
			else
				printf(".");
		}
		printf("\n");
	}
}

int main(){
	int a[9][27] ={
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	int *kek[9];
	ft_copy(kek, a);
	map_print(kek);
	t_square sqr;
	t_point sizex = {9, 27};
	sqr = check_placement(kek, sizex);
	printf("x = %d\ny = %d\nsize = %d\n", sqr.start.x, sqr.start.y, sqr.size);
}