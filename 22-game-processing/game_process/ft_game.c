#include "../cub3d.h"

int ft_quit(void)
{
	mlx_destroy_image(g_mlx, g_mlx_img);
	mlx_destroy_window(g_mlx, g_mlx_win);
	exit(0);
}

void ft_update_img(int key_code)
{
	if (key_code == UP || key_code == DN)
		g_ply.wlk = ft_collision(W_S);
	if (key_code == DN)
		g_ply.wlk = ft_collision(-W_S);
	if (key_code == RT)
	{
		g_ply.dgr = 90;
		g_ply.wlk = ft_collision(W_S);
	}
	if (key_code == LT)
	{
		g_ply.dgr = -90;
		g_ply.wlk = ft_collision(W_S);
	}
	if (key_code == LT_ROT)
		g_ply.trn -= T_S;
	if (key_code == RT_ROT)
		g_ply.trn += T_S;
	g_ply.x += g_ply.wlk * ft_cos(g_ply.trn + g_ply.dgr);
	g_ply.y += g_ply.wlk * ft_sin(g_ply.trn + g_ply.dgr);
	g_ply.wlk = 0;
	g_ply.dgr = 0;
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

void ft_bmp_header()
{
	g_bmp_header.sgn = "BM";
	g_bmp_header.size = (g_info.rsl[0] * g_info.rsl[1] * 4) + 54;
	g_bmp_header.zr = 0;
	g_bmp_header.oft = 54;
	g_bmp_header.bmh = 40;
	g_bmp_header.pii = 1;
	g_bmp_header.bpp = 32;
}

int ft_bmp_init(void)
{
	if ((g_bmp_fd = open("image.bmp", O_RDWR | O_TRUNC | O_CREAT, 0600)) == ERR)
		return (ft_err("ERROR\nBM file error: somthing went wrong"));
	ft_bmp_header();
	write(g_bmp_fd, g_bmp_header.sgn, 2 * sizeof(char));
	write(g_bmp_fd, &g_bmp_header.size, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.oft, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.bmh, sizeof(int));
	write(g_bmp_fd, &g_info.rsl[0], sizeof(int));
	write(g_bmp_fd, &g_info.rsl[1], sizeof(int));
	write(g_bmp_fd, &g_bmp_header.pii, 2);
	write(g_bmp_fd, &g_bmp_header.bpp, 2);
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	return(0);
}

int ft_game_loop(void)
{
	if (g_bmp)
	{
		if (ft_bmp_init())
			return (ERR);
		ft_init_map_draw();
	}
	// ft_draw_map();
	// ft_draw_ply();
	// ft_draw_rays();
	else
	{
		ft_init_map_draw();
		mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
		mlx_hook(g_mlx_win, 2, 1L<<0, ft_move_player, &g_param);
		mlx_hook(g_mlx_win, 17, 1L<<3, ft_quit, &g_param);
	}
	return (0);
}

int ft_game(void)
{
	ft_game_var_init();
	if (!(g_mlx = mlx_init()))
		return (ft_err("ERROR\nmlx init error : somthing went wrong"));
	if (ft_game_texture())
		return (ERR);
	if (!g_bmp && !(g_mlx_win = mlx_new_window(g_mlx, g_info.rsl[0], g_info.rsl[1], "cub3D")))
		return (ft_err("ERROR\nmlx win error : somthing went wrong"));
	if (!(g_mlx_img = mlx_new_image(g_mlx, g_img.rsl[0], g_img.rsl[1])))
		return (ft_err("ERROR\nmlx img error : somthing went wrong"));
	if (!(g_mlx_str = (int*)mlx_get_data_addr(g_mlx_img, &g_img.bpp, &g_img.sz_ln, &g_img.e)))
		return (ft_err("ERROR\nmlx img addr error : somthing went wrong"));
	ft_game_loop();
	return (0);
}
