#include "../cub3d.h"

void ft_game_var_init(void)
{
	g_img.rsl[0] = g_info.rsl[0];
	g_img.rsl[1] = g_info.rsl[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_info.rsl[0] * 4;
	g_ray.agl = ((float)AGL * 2) / (float)g_info.rsl[0];

}

int ft_is_wall(int x, int y)
{
	int i;
	int j;

	i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
	j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
	if (g_map[i][j] == '1' || g_map[i][j] == '2')
		return (1);
	return (0);
}


void ft_ray_dir(float agl)
{
	g_ray.r = 0;
	g_ray.l = 0;
	g_ray.u = 0;
	g_ray.d = 0;
	g_ray.v = 1;
	if (ft_sin(agl) > 0)
		g_ray.d = 1;
	else
		g_ray.u = 1;
	if (ft_cos(agl) > 0)
		g_ray.r = 1;
	else
		g_ray.l = 1;
}

float ft_hit(float o)
{
	float h_hit;
	float v_hit;

	ft_ray_dir(o + g_ply.trn);
	h_hit = ft_h_hit(o + g_ply.trn);
	v_hit = ft_v_hit(o + g_ply.trn);
	if (h_hit < v_hit)
	{
		g_ray.v = 0;
		g_ray.x = g_hit.x_h;
		g_ray.y = g_hit.y_h;
		return (h_hit);
	}
	g_ray.x = g_hit.x_v;
	g_ray.y = g_hit.y_v;
	return (v_hit);
}

void ft_ply_init(void)
{
	int i;
	int j;

	i = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
			{
				g_ply.x = j * SZ + SZ / 2;
				g_ply.y = i * SZ + SZ / 2;
				if (g_map[i][j] == 'N')
					g_ply.trn = -90;
				if (g_map[i][j] == 'E')
					g_ply.trn = 180;
				if (g_map[i][j] == 'S')
					g_ply.trn = 90;
				if (g_map[i][j] == 'W')
					g_ply.trn = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}

// void ft_ply_init_ok(int i, int j)
// {
// 	g_ply.x = j * SZ + SZ / 2;
// 	g_ply.y = i * SZ + SZ / 2;
// 	if (g_map[i][j] == 'N')
// 		g_ply.trn = -90;
// 	if (g_map[i][j] == 'E')
// 		g_ply.trn = 180;
// 	if (g_map[i][j] == 'S')
// 		g_ply.trn = 90;
// 	if (g_map[i][j] == 'W')
// 		g_ply.trn = 0;
// }