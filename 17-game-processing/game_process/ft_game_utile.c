#include "../cub3d.h"

void ft_game_var_init(void)
{
	g_img.rsl[0] = g_info.rsl[0];
	g_img.rsl[1] = g_info.rsl[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_info.rsl[0] * 4;
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

// float ft_tan(int o)
// {
// 	return (tan(o * M_PI / 180));
// }

float ft_y(float y)
{
	return (y * g_img.rsl[0]);
}

int ft_crcl(float o, int r)
{
	float x;
	float y;

	x = g_ply.x + r * ft_cos(o + g_ply.trn);
	y = g_ply.y + r * ft_sin(o + g_ply.trn);
	return (ft_y(y) + x);
}

// void ft_line(float o, int a)
// {
// 	int i;

// 	i = g_ply.x + ft_y(g_ply.y);
// 	while (i != a)
// 	{
// 		g_mlx_str[i] = C_PL;
// 		i += ft_cos(o) + ft_y(ft_sin(o));
// 	}
// }

// int ft_h_int(float x, float y, float o)
// {
// 	int i;
// 	int j;

// 	while (1)
// 	{
// 		j = x / SZ;
// 		i = y / SZ;
// 		if (g_map[i][j] == '1' || g_map[i][j] == '2')
// 			return (x + ft_y(y));
// 		x += SZ / ft_tan(o);
// 		y += SZ;
// 	}
// 	return (0);
// }

// int ft_v_int(float x, float y, float o)
// {
// 	int i;
// 	int j;

// 	while (1)
// 	{
// 		j = x / SZ;
// 		i = y / SZ;
// 		if (g_map[i][j] == '1' || g_map[i][j] == '2')
// 			return (x + ft_y(y));
// 		y += SZ * ft_tan(o);
// 		x += SZ;
// 	}
// 	return (0);
// }

// int ft_intrc(float o)
// {
// 	float x;
// 	float y;
// 	int h_int;
// 	int v_int;

// 	y = ((g_ply.y / SZ) - (int)(g_ply.y / SZ)) * SZ;
// 	x = g_ply.x - (g_ply.y - y) / ft_tan(o);

// 	h_int = ft_h_int(x, y, o);
// 	v_int = ft_v_int(x, y, o);
// 	if (h_int > v_int) 
// 		return (h_int);
// 	return (v_int);
// }

void ft_ply_init(int i, int j)
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
}
