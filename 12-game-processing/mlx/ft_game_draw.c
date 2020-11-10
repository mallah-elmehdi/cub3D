#include "../cub3d.h"

void ft_draw_rect(int x, int y, int color)
{
	int a;
	int b;

	a = 0;
	while (a < SIZE)
	{
		b = 0;
		while (b < SIZE)
		{
			g_mlx_str[(x * SIZE) + b + (((y * SIZE) + a) * g_img.res[0])] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	int i;

	i = 0;
	while (g_mlx_str[(g_player.x * SIZE) + i + ((g_player.y * (SIZE)) * g_infos.resolution[0])] == 0xFFFFFF)
	{
		g_mlx_str[(g_player.x * SIZE) + i + ((g_player.y * (SIZE)) * g_infos.resolution[0])] = 0xFC1281;
		i++;
	}
}

void ft_draw_player(void)
{

	int a;
	int b;

	a = 0;
	while (a < SIZE_PLAYER)
	{
		b = 0;
		while (b < SIZE_PLAYER)
		{
			g_mlx_str[g_player.x + b + ((g_player.y + a) * g_img.res[0])] = g_player.color;
			b++;
		}
		a++;
	}
}
