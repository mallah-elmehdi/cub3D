#include "../cub3d.h"

void ft_draw_rect(int **mlx_str, int x, int y, int color)
{
	int a;
	int b;

	a = 0;
	while (a < SIZE)
	{
		b = 0;
		while (b < SIZE)
		{
			mlx_str[0][(x * SIZE) + b + (((y * SIZE) + a) * g_infos.resolution[0])] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(int **mlx_str)
{
	int i;

	i = 0;
	while (mlx_str[0][(g_player_x * SIZE) + 11 + i + ((g_player_y * (SIZE + 5)) * g_infos.resolution[0])] == 0xFFFFFF)
	// while (i < 1000)
	{
		mlx_str[0][(g_player_x * SIZE) + 11 + i + ((g_player_y * (SIZE + 5)) * g_infos.resolution[0])] = 0xFC1281;
		i++;
	}
}

void ft_draw_player(int **mlx_str)
{
	int a;
	int b;

	a = 0;
	while (a < SIZE_PLAYER)
	{
		b = 0;
		while (b < SIZE_PLAYER)
		{
			mlx_str[0][(g_player_x * SIZE) + b + (((g_player_y * SIZE) + a) * g_infos.resolution[0])] = 0xFC1281;
			b++;
		}
		a++;
	}
	ft_draw_rays(mlx_str);
	
}
