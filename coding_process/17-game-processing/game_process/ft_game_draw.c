#include "../cub3d.h"

void ft_draw_rect(int x, int y, int color)
{
	int a;
	int b;
	int idx;

	a = 0;
	while (a < SZ)
	{
		b = 0;
		while (b < SZ)
		{
			idx = (x * SZ) + b + ft_y((y * SZ) + a);
			g_mlx_str[idx] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	int a;
	float b;
	int idx;

	b = 0;
	while (b < 30)
	{
		a = 0;
		while (1)
		{
			idx = ft_crcl(b, a);
			if (g_mlx_str[idx] != C_PL && g_mlx_str[idx] != C_0)
				break ;
			g_mlx_str[idx] = C_PL;
			a++;
		}
		b++;
	}
}

void ft_draw_rays_2(void)
{
	int a;
	float b;
	int idx;

	b = 0;
	while (b > -30)
	{
		a = 0;
		while (1)
		{
			idx = ft_crcl(b, a);
			if (g_mlx_str[idx] != C_PL && g_mlx_str[idx] != C_0)
				break ;
			g_mlx_str[idx] = C_PL;
			a++;
		}
		b--;
	}
}

void ft_draw_player(void)
{

	float b;
	int a;
	int idx;

	g_ply.x += g_ply.wlk * ft_cos(g_ply.trn);
	g_ply.y += g_ply.wlk * ft_sin(g_ply.trn);
	g_ply.wlk = 0;

	b = 0;
	while (b < 360)
	{
		a = 0;
		while (a <= SZ_PY)
		{
			idx = ft_crcl(b, a);
			g_mlx_str[idx] = C_PL;
			a++;
		}
		b++;
	}
}

void ft_draw_map(void)
{
	int i;
	int j;

	i = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (g_map[i][j] == '1')
				ft_draw_rect(j, i, C_1);
			else if (g_map[i][j] == '2')
				ft_draw_rect(j, i, C_2);
			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
				ft_draw_rect(j, i, C_0);
			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
				ft_ply_init(i, j);
			j++;
		}
		i++;
	}
}