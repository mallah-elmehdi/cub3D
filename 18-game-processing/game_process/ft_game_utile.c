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

float ft_cos(float o)
{
	return (cos(o * PI / 180));
}

float ft_sin(float o)
{
	return (sin(o * PI / 180));
}

float ft_tan(float o)
{
	return (tan(o * PI / 180));
}

int ft_y(float i)
{
	return (i * g_img.rsl[0]);
}

int ft_is_wall(int x, int y)
{
	if (g_mlx_str[x + ft_y(y)] == C_1 || g_mlx_str[x + ft_y(y)] == C_2)
		return (1);
	return (0);
}

void ft_hit_init_h(int *x, int *y, int *add, int o)
{
	*add = g_ray.u ? -1 : 0;
	if (g_ray.u)
		*y = (int)(g_ply.y / SZ) * SZ;
	else if (g_ray.d)
		*y = (int)(g_ply.y / SZ + 1) * SZ;
	else
		*y = g_ply.y;	
	*x = g_ply.x + (*y - g_ply.y) / ft_tan(o);
	g_ystp = g_ray.u ? -SZ : SZ;
	g_xstp = SZ / ft_tan(o);
	if ((g_ray.l && g_xstp > 0) || (g_ray.r && g_xstp < 0))
		g_xstp *= -1;
}

int ft_h_hit(float o)
{
	int x;
	int y;
	int add;
	
	ft_hit_init_h(&x, &y, &add, o);
	while (x > 0 && y + add > 0 && x < g_img.rsl[0] && y + add < g_img.rsl[1])
	{
		if (ft_is_wall(x, y + add))
		{
			g_h.x = x;
			g_h.y = y;
			return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
		}
		x += g_xstp;
		y += g_ystp;
	}
	return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
}

void ft_hit_init_v(int *x, int *y, int *add, int o)
{
	*add = g_ray.l ? -1 : 0;
	if (g_ray.r)
		*x = (int)(g_ply.x / SZ + 1) * SZ;
	else if (g_ray.l)
		*x = (int)(g_ply.x / SZ) * SZ;
	else
		*x = g_ply.x;	
	*y = g_ply.y + (*x - g_ply.x) * ft_tan(o);
	g_xstp = g_ray.l ? -SZ : SZ;
	g_ystp = SZ * ft_tan(o);
	if ((g_ray.u && g_ystp > 0) || (g_ray.d && g_ystp < 0))
		g_ystp *= -1;
}

int ft_v_hit(float o)
{
	int x;
	int y;
	int add;
	
	ft_hit_init_v(&x, &y, &add, o);
	while (x > 0 && y + add > 0 && x < g_img.rsl[0] && y + add < g_img.rsl[1])
	{
		if (ft_is_wall(x, y + add))
		{
			g_h.x = x;
			g_h.y = y;
			return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
		}
		x += g_xstp;
		y += g_ystp;
	}
	return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
}

void ft_ray_dir(float agl)
{
	g_ray.r = 0;
	g_ray.l = 0;
	g_ray.u = 0;
	g_ray.d = 0;
	if (ft_sin(agl) > 0)
		g_ray.d = 1;
	if (ft_sin(agl) < 0)
		g_ray.u = 1;
	if (ft_cos(agl) > 0)
		g_ray.r = 1;
	if (ft_cos(agl) < 0)
		g_ray.l = 1;
}

int ft_hit(float o)
{
	int h_hit;
	int v_hit;

	ft_ray_dir(o + g_ply.trn);
	h_hit = ft_h_hit(o + g_ply.trn);
	v_hit = ft_v_hit(o + g_ply.trn);
	if (h_hit < 0) 
		h_hit *= -1;
	if (v_hit < 0) 
		v_hit *= -1;
	if (h_hit < v_hit)
	{
		g_v.x  = -1;
		g_v.y  = -1;
		return (h_hit);
	}
	g_h.x  = -1;
	g_h.y  = -1;
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
