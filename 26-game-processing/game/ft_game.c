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
		// ft_draw_map();
		// ft_draw_ply();
		// ft_draw_rays();
		mlx_put_image_to_window(g_mlx, g_mlx_win, g_mlx_img, 0, 0);
		mlx_hook(g_mlx_win, 2, 1L << 0, ft_move_player, &g_param);
		mlx_hook(g_mlx_win, 17, 1L << 3, ft_quit, &g_param);
	}
	return (0);
}

int		ft_game(void)
{
	ft_game_var_init();
	if (g_hm_spt && !(g_spt_s = malloc(sizeof(struct s_spt) * g_hm_spt)))
		return (ERR);
	if (g_hm_spt)
		ft_spt();
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

// ================================================ 2D

void ft_draw_rect(int x, int y, int color)
{
	int a;
	int b;
	int i;

	a = 0;
	while (a < SZ)
	{
		b = 0;
		while (b < SZ)
		{
			i = x * SZ + b + ft_y(y * SZ + a);
			g_mlx_str[i] = color;
			b++;
		}
		a++;
	}
}

void ft_draw_ply(void)
{
	float a;
	float b;
	int x;
	int y;

	a = 0;
	while (a < 360)
	{
		b = 0;
		while (b < SZ_PY)
		{
			x = g_ply.x + b * ft_cos(a);
			y = g_ply.y + b * ft_sin(a);
			g_mlx_str[x + ft_y(y)] = C_PL;
			b++;
		}
		a++;
	}
}

void ft_draw_rays(void)
{
	float a;
	float b;
	int x;
	int y;
	int stop;

	a = -AGL;
	while (a <= AGL)
	{
		b = 0;
		stop = ft_hit(a);
		while (b <= stop)
		{
			x = g_ply.x + b * ft_cos(a + g_ply.trn);
			y = g_ply.y + b * ft_sin(a + g_ply.trn);
				g_mlx_str[x + ft_y(y)] = C_PL;
			b++;
		}
		
		a += 0.3;
	}
}

void ft_draw_map(void)
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
				ft_draw_rect(j, i, C_1);
			else if (g_map[i][j] == '2')
				ft_draw_rect(j, i, C_2);
			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
				ft_draw_rect(j, i, C_0);
			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
				ft_ply_init_ok(i, j);
			j++;
		}
		i++;
	}
}

void ft_ply_init_ok(int i, int j)
{
	g_ply.x = j * SZ + SZ / 2;
	g_ply.y = i * SZ + SZ / 2;
	if (g_map[i][j] == 'N')
		g_ply.trn = -90;
	if (g_map[i][j] == 'E')
		g_ply.trn = 180;
	if (g_map[i][j] == 'S')
		g_ply.trn = 90;
	if (g_map[i][j] == 'W')
		g_ply.trn = 0;
}