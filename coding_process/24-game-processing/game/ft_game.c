/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:23:31 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:23:33 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_move_player(int key_code)
{
	if (key_code == ESC)
		ft_quit();
	if (ft_allowed_key(key_code))
		ft_update_img(key_code);
	return (0);
}

int		ft_game_loop(void)
{
	if (g_bmp)
	{
		if (ft_bmp_init())
			return (ERR);
		ft_init_map_draw();
	}
	else
	{
		ft_init_map_draw();
		mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
		mlx_hook(g_mlx_win, 2, 1L << 0, ft_move_player, &g_param);
		mlx_hook(g_mlx_win, 17, 1L << 3, ft_quit, &g_param);
	}
	return (0);
}

int		ft_game(void)
{
	ft_game_var_init();
	if (g_hm_spt)
		g_spt_s = malloc(sizeof(struct s_spt) * g_hm_spt);
	if (!(g_mlx = mlx_init()))
		return (ft_err("ERROR\nmlx init error : somthing went wrong"));
	if (ft_game_texture())
		return (ERR);
	if (!g_bmp && !(g_mlx_win =
		mlx_new_window(g_mlx, g_info.rsl[0], g_info.rsl[1], "cub3D")))
		return (ft_err("ERROR\nmlx win error : somthing went wrong"));
	if (!(g_mlx_img = mlx_new_image(g_mlx, g_img.rsl[0], g_img.rsl[1])))
		return (ft_err("ERROR\nmlx img error : somthing went wrong"));
	if (!(g_mlx_str =
		(int*)mlx_get_data_addr(g_mlx_img, &g_img.bpp, &g_img.sz_ln, &g_img.e)))
		return (ft_err("ERROR\nmlx img addr error : somthing went wrong"));
	if (ft_game_loop())
		return (ERR);
	return (0);
}
