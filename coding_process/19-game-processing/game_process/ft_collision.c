#include "../cub3d.h"

int ft_collision(int spd)
{
	int x;
	int y;

	while (1)
	{
		x = g_ply.x + spd * ft_cos(g_ply.trn);
		y = g_ply.y + spd * ft_sin(g_ply.trn);
		if(g_mlx_str[x + ft_y(y)] == C_0 || g_mlx_str[x + ft_y(y)] == C_PL)
			return(spd);
		if (spd < 0)
			spd++;
		else
			spd--; 
	}
	return (spd);
}