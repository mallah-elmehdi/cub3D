/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utile_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:40:02 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:40:05 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hit_init_h(float *x, float *y, int *add, float o)
{
	*add = g_ray.u ? -1 : 0;
	if (g_ray.u)
		*y = (int)(g_ply.y / SZ) * SZ;
	else
		*y = (int)(g_ply.y / SZ + 1) * SZ;
	*x = g_ply.x + (*y - g_ply.y) / ft_tan(o);
	g_ystp = g_ray.u ? -SZ : SZ;
	g_xstp = SZ / ft_tan(o);
	if ((g_ray.l && g_xstp > 0) || (g_ray.r && g_xstp < 0))
		g_xstp *= -1;
}

float	ft_h_hit(float o)
{
	float	x;
	float	y;
	int		add;

	ft_hit_init_h(&x, &y, &add, o);
	while ((int)(x / SZ) < g_map_width
		&& (int)((y + add) / SZ) < g_map_height
		&& x > 0 && y + add > 0)
	{
		if (ft_is_wall(x, y + add))
		{
			g_hit.x_h = x;
			g_hit.y_h = y;
			return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
		}
		ft_is_spt(x, y + add);
		x += g_xstp;
		y += g_ystp;
	}
	g_hit.x_h = x;
	g_hit.y_h = y;
	return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
}

void	ft_hit_init_v(float *x, float *y, int *add, float o)
{
	*add = g_ray.l ? -1 : 0;
	if (g_ray.r)
		*x = (int)(g_ply.x / SZ + 1) * SZ;
	else
		*x = (int)(g_ply.x / SZ) * SZ;
	*y = g_ply.y + (*x - g_ply.x) * ft_tan(o);
	g_xstp = g_ray.l ? -SZ : SZ;
	g_ystp = SZ * ft_tan(o);
	if ((g_ray.u && g_ystp > 0) || (g_ray.d && g_ystp < 0))
		g_ystp *= -1;
}

float	ft_v_hit(float o)
{
	float	x;
	float	y;
	int		add;

	ft_hit_init_v(&x, &y, &add, o);
	while ((int)((x + add) / SZ) < g_map_width
		&& (int)(y / SZ) < g_map_height
		&& x + add > 0 && y > 0)
	{
		if (ft_is_wall(x + add, y))
		{
			g_hit.x_v = x;
			g_hit.y_v = y;
			return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
		}
		ft_is_spt(x + add, y);
		x += g_xstp;
		y += g_ystp;
	}
	g_hit.x_v = x;
	g_hit.y_v = y;
	return (sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2)));
}
