#include "../cub3d.h"

void ft_draw_rect(int x, int y, int color)
{
	int a;
	int b;
	int i;

	a = 0;
	while (a < SZ)
	{
		b = 0;
		while (b < SZ)
		{
			i = x * SZ + b + ft_y(y * SZ + a);
			g_mlx_str[i] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_ply(void)
{
	float a;
	float b;
	int x;
	int y;

	a = 0;
	while (a < 360)
	{
		b = 0;
		while (b < SZ_PY)
		{
			x = g_ply.x + b * ft_cos(a);
			y = g_ply.y + b * ft_sin(a);
			g_mlx_str[x + ft_y(y)] = C_PL;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	float a;
	float b;
	int x;
	int y;
	int stop;

	a = -30;
	while (a <= 30)
	{
		b = 0;
		stop = ft_hit(a);
		while (b <= stop)
		{
			x = g_ply.x + b * ft_cos(a + g_ply.trn);
			y = g_ply.y + b * ft_sin(a + g_ply.trn);
			if (g_mlx_str[x + ft_y(y)] == C_0)
				g_mlx_str[x + ft_y(y)] = C_PL;
			b++;
		}
		
		a+=0.7;
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