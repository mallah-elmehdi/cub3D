
#include "cub3d.h"

int	ft_skip_space(char *line)
{
	int i;

	i = 0;
	while (line[i] == 32)
		i++;
	return (i);
}