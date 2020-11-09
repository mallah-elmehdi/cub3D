#include "../cub3d.h"

int ft_move_player(int key_code)
{
	printf("%d\n", key_code);
	return (0);
}

int ft_game_loop()
{
	void *mlx_img;
	int *mlx_str;

	if (!(mlx_img = mlx_new_image(g_mlx, g_infos.resolution[0], g_infos.resolution[1])))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	if (!(mlx_str = (int *)mlx_get_data_addr(mlx_img, &g_img.bpp, &g_img.size_line, &g_img.endian)))
		return (ft_err("EROOR\nerror: something went wrong please try again"));
	mlx_key_hook(g_mlx_win, ft_move_player, g_param);
	ft_game_init(&mlx_str);
	ft_draw_player(&mlx_str);
	mlx_put_image_to_window(g_mlx, g_mlx_win, mlx_img, 0, 0);
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
