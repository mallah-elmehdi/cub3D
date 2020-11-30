#include "../cub3d.h"

void ft_quit(void)
{
	mlx_destroy_image(g_mlx, g_mlx_img);
	mlx_destroy_window(g_mlx, g_mlx_win);
	exit(0);
}

void ft_update_img(int key_code)
{
	if (key_code == UP)
		g_ply.wlk = ft_collision(W_S);
	if (key_code == DN)
		g_ply.wlk = ft_collision(-W_S);
	if (key_code == LT_ROT)
		g_ply.trn -= T_S;
	if (key_code == RT_ROT)
		g_ply.trn += T_S;
	g_ply.x += g_ply.wlk * ft_cos(g_ply.trn);
	g_ply.y += g_ply.wlk * ft_sin(g_ply.trn);
	g_ply.wlk = 0;
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
	ft_draw_map();
	ft_draw_ply();
	ft_draw_rays();
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
	mlx_key_hook(g_mlx_win, ft_move_player, g_param);
}

void ft_game(void)
{
	ft_game_var_init();
	g_mlx = mlx_init();
	g_mlx_win = mlx_new_window(g_mlx, g_info.rsl[0], g_info.rsl[1], "cub3D");
	g_mlx_img = mlx_new_image(g_mlx, g_img.rsl[0], g_img.rsl[1]);
	g_mlx_str = (int*)mlx_get_data_addr(g_mlx_img, &g_img.bpp, &g_img.sz_ln, &g_img.e);
	ft_game_loop();
}
