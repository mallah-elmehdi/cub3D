
#include "cub3d.h"

int ft_is_player(char c)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		return (1);
	return (0);
}

void free_it_double_int(int **s, int counter)
{
	while (counter > 0)
	{
		free(s[counter]);
		s[counter--] = NULL;
	}
	free(s);
	s = NULL;
}

int ft_matrix_lenght(int **map)
{
	int matrix;

	matrix = sizeof(map) / sizeof(int*);
	return (matrix);
}

int ft_array_lenght(int *map)
{
	int array;

	array = sizeof(map) / sizeof(int);
	return (array);
}

