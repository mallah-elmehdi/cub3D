
#include "cub3d.h"

int ft_is_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void free_it(char **s)
{
	free(*s);
	*s = NULL;
}

void free_it_double(char **s, int counter)
{
	while (counter > 0)
	{
		free(s[counter]);
		s[counter--] = NULL;
	}
	free(s);
	s = NULL;
}

void ft_initilisation(struct the_infos *info, int ***map)
{
	info->resolution[0] = -1;
	info->resolution[1] = -1;
	info->floor = -1;
	info->ceilling = -1;
	info->s_texture = NULL;
	info->so_texture = NULL;
	info->no_texture = NULL;
	info->we_texture = NULL;
	info->ea_texture = NULL;
	*map = (int **)malloc(sizeof(int*) * 1);
	**map = (int *)malloc(sizeof(int) * 1);
	g_map_start = 1;
}

int ft_is_info_done(struct the_infos *info)
{
	if (info->resolution[0] == -1 && info->resolution[1] == -1)
		return (0);
	if (info->floor == -1)
		return (0);
	if (info->ceilling == -1)
		return (0);
	if (info->s_texture == NULL)
		return (0);
	if (info->so_texture == NULL)
		return (0);
	if (info->no_texture == NULL)
		return (0);
	if (info->we_texture == NULL)
		return (0);
	if (info->ea_texture == NULL)
		return (0);
	return (1);
}