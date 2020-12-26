/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:43:30 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:43:44 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_game_var_init(void)
{
	g_img.rsl[0] = g_info.rsl[0];
	g_img.rsl[1] = g_info.rsl[1];
	g_img.bpp = 32;
	g_img.sz_ln = g_info.rsl[0] * 4;
	g_ray.agl = ((float)AGL * 2) / (float)g_info.rsl[0];
}

int		ft_is_wall(int x, int y)
{
	int		i;
	int		j;

	i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
	j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
	i *= i < 0 ? 0 : 1;
	j *= j < 0 ? 0 : 1;
	if (g_map[i][j] == '1')
		return (1);
	return (0);
}

void	ft_ray_dir(float agl)
{
	g_ray.r = 0;
	g_ray.l = 0;
	g_ray.u = 0;
	g_ray.d = 0;
	g_ray.v = 1;
	if (ft_sin(agl) > 0)
		g_ray.d = 1;
	else
		g_ray.u = 1;
	if (ft_cos(agl) > 0)
		g_ray.r = 1;
	else
		g_ray.l = 1;
}

float	ft_hit(float o, int x)
{
	float	h_hit;
	float	v_hit;

	ft_ray_dir(o + g_ply.trn);
	h_hit = ft_h_hit(o + g_ply.trn, x);
	v_hit = ft_v_hit(o + g_ply.trn, x);
	if (h_hit < v_hit)
	{
		g_ray.v = 0;
		g_ray.x = g_hit.x_h;
		g_ray.y = g_hit.y_h;
		return (h_hit);
	}
	g_ray.x = g_hit.x_v;
	g_ray.y = g_hit.y_v;
	return (v_hit);
}
