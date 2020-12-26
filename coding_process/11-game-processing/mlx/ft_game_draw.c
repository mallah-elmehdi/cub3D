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
			g_mlx_str[(x * SIZE) + b + (((y * SIZE) + a) * g_infos.resolution[0])] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	int i;

	i = 0;
	while (g_mlx_str[(g_player.x * SIZE)+ i + ((g_player.y * (SIZE)) * g_infos.resolution[0])] == 0xFFFFFF)
	{
		g_mlx_str[(g_player.x * SIZE)+ i + ((g_player.y * (SIZE)) * g_infos.resolution[0])] = 0xFC1281;
		i++;
	}
}

void ft_draw_player(void)
{
	float o;
	float a = 0;
	// int b = 0;
    o = 0;
	while (o < 360)
	{
        // a = (g_player.x * SIZE * 3/2 + 12 * cos(o * PI/180) + g_player.y * SIZE * 3/2 * sin(o * PI/180) * g_infos.resolution[0]);
        a = g_player.x * SIZE * 3/2 * cos(o * PI/180);
        printf("%f\n", a);
	    // g_mlx_str[(int)(g_player.x * SIZE * 3/2 + 12 * cos(o) + g_player.y * SIZE * 3/2 * sin(o) * g_infos.resolution[0])] = 0xFC1281;
	    o++;
	}
	// while (a < SIZE_PLAYER)
	// {
	// 	b = 0;
	// 	while (b < SIZE_PLAYER)
	// 	{
	// 		g_mlx_str[(g_player.x * SIZE) + b + (((g_player.y * SIZE) + a) * g_infos.resolution[0])] = 0xFC1281;
	// 		b++;
	// 	}
	// 	a++;
	// }
	// ft_draw_rays();
}
