#include "../cub3d.h"

void ft_draw_rect(int x, int y, int color)
{
	int a;
	int b;

	a = 0;
	while (a < SZ)
	{
		b = 0;
		while (b < SZ)
		{
			g_mlx_str[(x * SZ) + b + (((y * SZ) + a) * g_img.res[0])] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	int i;
	int a;
	int x;
	int y;

	a = 0;
	x = g_ply.x;
	y = g_ply.y;
	
	while (a <= 45)
	{
		i = 0;
		while (g_mlx_str[x + i*ft_cos(a) + ((y + i*ft_sin(a)) * g_img.res[0])] == 0xFFFFFF)
		{
			g_mlx_str[x + i*ft_cos(a) + ((y + i*ft_sin(a)) * g_img.res[0])] = 0xFC1281;
			i++;
		}
		// if (a < 45)
		// 	g_mlx_str[x + (y * g_img.res[0])] = 0xFFFFFF;
		a++;
	}
}
void ft_draw_player(void)
{

	int a;
	int b;
	int i;

	i = SZ_PLY / 2;
	a = -i;
	while (a < i)
	{
		b = -i;
		while (b < i)
		{
			g_mlx_str[g_ply.x + b + ((g_ply.y + a) * g_img.res[0])] = g_ply.color;
			b++;
		}
		a++;
	}
	// ft_draw_rays();
}
