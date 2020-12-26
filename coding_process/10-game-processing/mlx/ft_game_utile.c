#include "../cub3d.h"

void ft_game_var_init(void)
{
	g_img.bpp = 32;
	g_img.size_line = g_infos.resolution[0] * 4;
}

void ft_game_init(int **mlx_str)
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
				ft_draw_rect(mlx_str, j, i, 3119323);
			else if (g_map[i][j] == '2')
				ft_draw_rect(mlx_str, j, i, 3119184);
			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
				ft_draw_rect(mlx_str, j, i, 16777215);
			if (ft_is_player(g_map[i][j]))
			{
				g_player_x = j;
				g_player_y = i;
			}
			j++;
		}
		i++;
	}
}