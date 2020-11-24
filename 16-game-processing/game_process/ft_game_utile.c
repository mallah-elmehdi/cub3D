#include "../cub3d.h"

void ft_game_var_init(void)
{
	g_ply.x = 0;
	g_ply.y = 0;
	g_ply.wdrc = 0;
	g_ply.tdrc = 0;
	g_ply.wspd = SZ_PY;
	g_ply.tspd = 10;

	g_img.rsl[0] = g_info.rsl[0];
	g_img.rsl[1] = g_info.rsl[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_info.rsl[0] * 4;
	
	g_mvt.rot = 0;
	g_mvt.lr = 0;
	g_mvt.pd = 0;
	g_mvt.agl = 60 / g_info.rsl[0];
}

int   ft_allowed_key(int key)
{
    if (key == UP || key == DN || key == RT
	|| key == LT || key == LT_ROT || key == RT_ROT)
        return (1);
    return (0);
}

float ft_cos(int o)
{
	return (cos(o * M_PI / 180));
}

float ft_sin(int o)
{
	return (sin(o * M_PI / 180));
}

float ft_y(int i)
{
	return (i * g_img.rsl[0]);
}

int ft_crcl(float o, int r)
{
	int x;
	int y;

	x = g_ply.x * SZ + g_mvt.lr * g_ply.wspd;
	x += r * ft_cos(o + g_mvt.rot*g_ply.tspd + g_ply.agl) + SZ/2;
	y = g_ply.y * SZ + g_mvt.pd * g_ply.wspd;
	y += r * ft_sin(o + g_mvt.rot*g_ply.tspd + g_ply.agl) + SZ/2;
	return (ft_y(y) + x);
}

void ft_ply_init(int i, int j)
{
	g_ply.x = j;
	g_ply.y = i;
	if (g_map[i][j] == 'N')
		g_ply.agl = -90;
	if (g_map[i][j] == 'E')
		g_ply.agl = 180;
	if (g_map[i][j] == 'S')
		g_ply.agl = 90;
	if (g_map[i][j] == 'W')
		g_ply.agl = 0;
}
