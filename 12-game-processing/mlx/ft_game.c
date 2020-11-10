#include "../cub3d.h"

void ft_quit(void)
{
	mlx_destroy_image(g_mlx, g_mlx_img);
	mlx_destroy_window(g_mlx, g_mlx_win);
	exit(0);
}

void ft_update_img(int key_code)
{
	// if (key_code == UP && g_mlx_str[g_player.x * SIZE_PLAYER + (g_player.y - 1) * g_img.res[0]] != 0xFFFFFF)
	// 	g_player.y -= SIZE_PLAYER;
	// if (key_code == DOWN && g_mlx_str[g_player.x * SIZE_PLAYER + (g_player.y + 1) * g_img.res[0]] != 0xFFFFFF)
		// g_player.y += SIZE_PLAYER;
	if (key_code == RIGHT && g_mlx_str[g_player.x + SIZE_PLAYER * 2 + g_player.y * g_img.res[0]] == 0xFFFFFF)
		g_player.x += SIZE_PLAYER;
	// if (key_code == LEFT && g_mlx_str[(g_player.x - 1) * SIZE_PLAYER + g_player.y * g_img.res[0]] != 0xFFFFFF)
	// 	g_player.x -= SIZE_PLAYER;
	mlx_destroy_image(g_mlx, g_mlx_img);
	ft_game_loop();
}

int ft_move_player(int key_code)
{
	if (key_code == ESC)
		ft_quit();
	if (ft_allowed_key(key_code))
		ft_update_img(key_code);
	return (0);
}

void ft_game_loop(void)
{
	g_mlx_img = mlx_new_image(g_mlx, g_img.res[0], g_img.res[1]);
	g_mlx_str = (int *)mlx_get_data_addr(g_mlx_img, &g_img.bpp, &g_img.size_line, &g_img.endian);
	mlx_key_hook(g_mlx_win, ft_move_player, g_param);
	ft_game_init();
	ft_draw_player();
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
}

void ft_game(void)
{
	ft_game_var_init();
	g_mlx = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx, g_infos.resolution[0], g_infos.resolution[1], "cub3d");
	ft_game_loop();
}
