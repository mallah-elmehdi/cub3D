#include "cub3d.h"

int ft_map_check_1(int i, int j)
{
	if (j != 0 && map[i][j + 1] != 0)
	{
		if (map[i][j + 1] == 0 
		|| ft_is_whitespace(map[i][j + 1])
		|| ft_is_whitespace(map[i][j - 1]))
			return (ft_err("MAP ERROR: incorrect map"));
	}
	if (i != 0 && map[i - 1][j] != 0 && map[i] != NULL)
	{
		if (map[i + 1][j] == 0 
		|| ft_is_whitespace(map[i + 1][j])
		|| map[i - 1][j] == 0
		|| ft_is_whitespace(map[i - 1][j]))
			return (ft_err("MAP ERROR: incorrect map"));
	}
	return (1);
}

int ft_map_check_2(int i, int j)
{
	if (j != 0 && map[i][j + 1] != 0 
		&& i != 0 && map[i - 1][j] != 0 && map[i] != NULL)
	{
		if ((map[i][j + 1] == 0 && ft_is_whitespace(map[i][j + 1])) 
		&& (map[i - 1][j] == 0 || ft_is_whitespace(map[i - 1][j]))
		&& (map[i + 1][j] == 0 || ft_is_whitespace(map[i + 1][j]))
		&& ft_is_whitespace(map[i][j - 1]))
			return (ft_err("MAP ERROR: incorrect map"));
}
	return (1);
}

int ft_map_check_3(int i, int j)
{
	if (j != 0 && map[i][j + 1] != 0)
	{
		if (map[i][j + 1] == '0' 
		|| map[i][j + 1] == '2'
		|| ft_is_player(map[i][j + 1])
		|| map[i][j - 1] == '0'
		|| map[i][j - 1] == '2'
		|| ft_is_player(map[i][j - 1]))
			return (ft_err("MAP ERROR: incorrect map"));
	}
	if (i != 0 && map[i - 1][j] != 0 && map[i] != NULL)
	{
		if (map[i + 1][j] == '0' 
		|| map[i + 1][j] == '2'
		|| ft_is_player(map[i + 1][j])
		|| map[i - 1][j] == '0'
		|| map[i - 1][j] == '2'
		|| ft_is_player(map[i - 1][j]))
			return (ft_err("MAP ERROR: incorrect map"));
	}
	return (1);
}