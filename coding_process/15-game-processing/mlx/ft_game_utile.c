#include "../cub3d.h"

void ft_game_var_init(void)
{
    g_ply.color = 0xFC1281;
	g_ply.x = 0;
	g_ply.y = 0;
	g_img.res[0] = g_infos.resolution[0];
	g_img.res[1] = g_infos.resolution[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_infos.resolution[0] * 4;
	// g_move.up = 0;
	// g_move.down = 0;
	// g_move.right = 0;
	// g_move.left = 0;
}

int   ft_allowed_key(int key)
{
    if (key == UP || key == DOWN || key == RIGHT
	|| key == LEFT || key == LEFT_ROT || key == RIGHT_ROT)
        return (1);
    return (0);
}

int ft_cos(int o)
{
	if (cos(o * M_PI / 180) >= 0.5)
		return (1);
	if (cos(o * M_PI / 180) <= -0.5)
		return (-1);
	return (0);
}

int ft_sin(int o)
{
	if (sin(o * M_PI / 180) >= 0.5)
		return (1);
	if (sin(o * M_PI / 180) <= -0.5)
		return (-1);
	return (0);
}

void ft_game_init(void)
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
				ft_draw_rect(j, i, CLR_1);
			else if (g_map[i][j] == '2')
				ft_draw_rect(j, i, CLR_2);
			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
				ft_draw_rect(j, i, CLR_0);
			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
			{
				g_ply.x = j * SZ + SZ / 2;
				g_ply.y = i * SZ + SZ / 2;
				g_ply.face = g_map[i][j];
			}
			j++;
		}
		i++;
	}
}