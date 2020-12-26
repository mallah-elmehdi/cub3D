/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:33:43 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:33:48 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_quit(void)
{
	mlx_destroy_image(g_mlx, g_mlx_img);
	mlx_destroy_window(g_mlx, g_mlx_win);
	exit(0);
}

int		ft_update_img(int key_code)
{
	if (key_code == UP || key_code == DN)
		g_ply.wlk = ft_collision(W_S);
	if (key_code == DN)
		g_ply.wlk = ft_collision(-W_S);
	if (key_code == RT && (g_ply.dgr = 90) > 0)
		g_ply.wlk = ft_collision(W_S);
	if (key_code == LT && (g_ply.dgr = -90) < 0)
		g_ply.wlk = ft_collision(W_S);
	if (key_code == LT_ROT)
		g_ply.trn -= T_S;
	if (key_code == RT_ROT)
		g_ply.trn += T_S;
	g_ply.x += g_ply.wlk * ft_cos(g_ply.trn + g_ply.dgr);
	g_ply.y += g_ply.wlk * ft_sin(g_ply.trn + g_ply.dgr);
	g_ply.wlk = 0;
	g_ply.dgr = 0;
	if (ft_game_loop())
		return (ERR);
	return (0);
}
