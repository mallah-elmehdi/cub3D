#include "../cub3d.h"

void ft_game_var_init(void)
{
	g_img.rsl[0] = g_info.rsl[0];
	g_img.rsl[1] = g_info.rsl[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_info.rsl[0] * 4;
}

int ft_is_wall(int x, int y)
{
	if (g_mlx_str[x + ft_y(y)] == C_1 || g_mlx_str[x + ft_y(y)] == C_2)
		return (1);
	return (0);
}


void ft_ray_dir(float agl)
{
	g_ray.r = 0;
	g_ray.l = 0;
	g_ray.u = 0;
	g_ray.d = 0;
	if (ft_sin(agl) > 0)
		g_ray.d = 1;
	else
		g_ray.u = 1;
	if (ft_cos(agl) > 0)
		g_ray.r = 1;
	else
		g_ray.l = 1;
}

int ft_hit(float o)
{
	int h_hit;
	int v_hit;

	ft_ray_dir(o + g_ply.trn);
	h_hit = ft_h_hit(o + g_ply.trn);
	v_hit = ft_v_hit(o + g_ply.trn);
	if (h_hit < v_hit)
		return (h_hit);
	return (v_hit);
}

void ft_ply_init(int i, int j)
{
	g_ply.x = (j + 1 / 2) * SZ;
	g_ply.y = (i + 1 / 2) * SZ;
	if (g_map[i][j] == 'N')
		g_ply.trn = -90;
	if (g_map[i][j] == 'E')
		g_ply.trn = 180;
	if (g_map[i][j] == 'S')
		g_ply.trn = 90;
	if (g_map[i][j] == 'W')
		g_ply.trn = 0;
}