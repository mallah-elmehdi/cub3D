#include "../cub3d.h"

int ft_cls_check()
{
	
}

int ft_collision(int spd)
{
	float x;
	float y;
	int add;
	int i;
	int j;

	add = spd > 0 ? 3 : -3;
	while (spd)
	{
		x = g_ply.x + (spd + add) * ft_cos(g_ply.trn);
		y = g_ply.y + (spd + add) * ft_sin(g_ply.trn);
		i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
		j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
		if(g_map[i][j] != '1' && g_map[i][j] != 0 && ft_cls_check())
			return(spd);
		if (spd < 0)
			spd++;
		else
			spd--; 
	}
	return (spd);
}