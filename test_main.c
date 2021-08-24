#include <stdio.h>
#include <stdlib.h>
#include "BSQ.h"
#include <unistd.h>

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

void map_print(int **kek, t_map map_par)
{
	for (int i = 0; i < map_par.number_of_lines; i++)
	{
		for (int j = 0; j < map_par.line_length; j++)
		{
			//printf(" %d ", kek[i][j]);
			if (kek[i][j] == 1)
				printf(" o ");
			else if (kek[i][j] == 2)
				printf("x");
			else if (kek[i][j] == 0)
				printf(" . ");
			else
				printf(" f ");

		}
		printf("\n");
	}
}

void map_print_sqr(int **kek, t_square max, t_map map_par)
{
	for (int i = max.start.y; i < max.start.y + max.size; i++)
	{
		for (int j = max.start.x; j < max.start.x + max.size; j++)
		{
			kek[i][j] = 3;
		}
	}
	for (int i = 0; i < map_par.number_of_lines; i++)
	{
		for (int j = 0; j < map_par.line_length; j++)
		{
			if (kek[i][j] == 1)
				printf(" o ");
			else if (kek[i][j] == 3)
				printf(" x ");
			else
				printf(" . ");
		}
		printf("\n");
	}
}

int main(){
	/*int a[9][27] ={
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};*/
	int **kek = NULL;
	//char str[] = {"9.ox\n...........................\n....o......................\n...........o...............\n...........................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................\n"};
	char *data;
	//ft_copy(kek, a);
	t_map map_par;
	main_parcer(&data, &map_par);
	write(1, "Fine\n", 5);
	//printf("Received string: %s\n", data);
	kek = parce_line(data, map_par);
	t_square sqr;
	map_print(kek, map_par);
	t_point sizex = {map_par.number_of_lines, map_par.line_length};
	sqr = check_placement(kek, sizex);
	printf("x = %d\ny = %d\nsize = %d\nOn map %dx%d\n", sqr.start.x, sqr.start.y, sqr.size, sizex.y, sizex.x);
	map_print_sqr(kek, sqr, map_par);
}