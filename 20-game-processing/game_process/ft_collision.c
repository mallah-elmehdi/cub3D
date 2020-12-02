#include "../cub3d.h"

int ft_collision(int spd)
{
	float x;
	float y;
	int i;
	int j;

	while (1)
	{
		x = g_ply.x + spd * ft_cos(g_ply.trn);
		y = g_ply.y + spd * ft_sin(g_ply.trn);
		i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
		j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
		if(g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
			return(spd);
		if (spd < 0)
			spd++;
		else
			spd--; 
	}
	return (spd);
}