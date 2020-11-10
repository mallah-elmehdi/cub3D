#include "../cub3d.h"

void ft_quit(void)
{
    mlx_destroy_image(g_mlx, g_mlx_img);
    mlx_destroy_window(g_mlx, g_mlx_win);
    exit(0);
}

void ft_update_img(int key_code)
{
    if (key_code == UP && g_map[g_player.y - 1][g_player.x] == '0')
    {
        g_map[g_player.y][g_player.x] = '0';
        g_map[g_player.y - 1][g_player.x] = g_player.face;
        mlx_destroy_image(g_mlx, g_mlx_img);
        ft_game_loop();
    }
    if (key_code == DOWN && g_map[g_player.y + 1][g_player.x] == '0')
    {
        g_map[g_player.y][g_player.x] = '0';
        g_map[g_player.y + 1][g_player.x] = g_player.face;
        mlx_destroy_image(g_mlx, g_mlx_img);
        ft_game_loop();
    }
    if (key_code == RIGHT && g_map[g_player.y][g_player.x + 1] == '0')
    {
        g_map[g_player.y][g_player.x] = '0';
        g_map[g_player.y][g_player.x + 1] = g_player.face;
        mlx_destroy_image(g_mlx, g_mlx_img);
        ft_game_loop();
    }
    if (key_code == LEFT && g_map[g_player.y][g_player.x - 1] == '0')
    {
        g_map[g_player.y][g_player.x] = '0';
        g_map[g_player.y][g_player.x - 1] = g_player.face;
        mlx_destroy_image(g_mlx, g_mlx_img);
        ft_game_loop();
    }
}

int ft_move_player(int key_code)
{
    if (key_code == ESC)
        ft_quit();
    if (ft_allowed_key(key_code))
        ft_update_img(key_code);
    printf("ok\n");
	return (0);
}

int ft_game_loop(void)
{
	if (!(g_mlx_img = mlx_new_image(g_mlx, g_infos.resolution[0], g_infos.resolution[1])))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	if (!(g_mlx_str = (int *)mlx_get_data_addr(g_mlx_img, &g_img.bpp, &g_img.size_line, &g_img.endian)))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	mlx_key_hook(g_mlx_win, ft_move_player, g_param);
	ft_game_init();
	ft_draw_player();
	mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
	return (0);
}

int ft_game(void)
{
	ft_game_var_init();
	if (!(g_mlx = mlx_init()))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	if (!(g_mlx_win = mlx_new_window(g_mlx, g_infos.resolution[0], g_infos.resolution[1], "cube3d (emallah)")))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	if (ft_game_loop())
		return (ERR);
	return (0);
}
