#include "../cub3d.h"

void ft_game_var_init(void)
{
    g_player.color = 0xFC1281;
	g_img.bpp = 32;
	g_img.size_line = g_infos.resolution[0] * 4;
}

int   ft_allowed_key(int key)
{
    if (key == UP || key == DOWN || key == RIGHT || key == LEFT || key == LEFT_ROT || key == RIGHT_ROT)
        return (1);
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
				ft_draw_rect(j, i, 3119323);
			else if (g_map[i][j] == '2')
				ft_draw_rect(j, i, 3119184);
			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
				ft_draw_rect(j, i, 16777215);
			if (ft_is_player(g_map[i][j]))
			{
				g_player.x = j;
				g_player.y = i;
				g_player.face = g_map[i][j];
			}
			j++;
		}
		i++;
	}
}