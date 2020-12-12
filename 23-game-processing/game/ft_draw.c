/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:27:32 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:27:34 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_with_txt(int y, int x, int ln_h)
{
	int		s_y;
	int		s_x;
	int		sz;
	int		btm_idx;

	sz = SZ;
	btm_idx = (ln_h > g_info.rsl[1]) ? g_info.rsl[1] : ln_h;
	s_x = g_ray.v ? g_ray.y % SZ : g_ray.x % SZ;
	while (btm_idx)
	{
		s_y = (y + ln_h / 2 - g_info.rsl[1] / 2) * ((float)sz / (float)ln_h);
		if (g_ray.u && !g_ray.v)
			g_mlx_str[x + ft_y(y)] = g_txt.g_no[s_y * SZ + s_x];
		else if (g_ray.d && !g_ray.v)
			g_mlx_str[x + ft_y(y)] = g_txt.g_so[s_y * SZ + s_x];
		else if (g_ray.v && g_ray.l)
			g_mlx_str[x + ft_y(y)] = g_txt.g_we[s_y * SZ + s_x];
		else if (g_ray.v && g_ray.r)
			g_mlx_str[x + ft_y(y)] = g_txt.g_ea[s_y * SZ + s_x];
		y++;
		btm_idx--;
	}
}

void	ft_rays(void)
{
	float	a;
	float	ray;
	float	ln_height;
	int		x;
	int		y;

	a = -AGL;
	x = 0;
	while (a <= AGL)
	{
		ray = ft_hit(a) * ft_cos(a);
		ln_height = (SZ / ray) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
		y = ((float)g_img.rsl[1] - 1) / 2 - (ln_height / 2);
		y = y < 0 ? 0 : y;
		ft_draw_with_txt(y, x, ln_height);
		if (g_spt)
			ft_draw_spt(x, 0);
		x++;
		a += g_ray.agl;
	}
	if (g_bmp)
		ft_draw_bmp();
}

void	ft_draw_cel_flr(void)
{
	long	i;

	i = 0;
	while (i < g_img.rsl[0] + ft_y((g_img.rsl[1] - 1) / 2))
		g_mlx_str[i++] = g_info.cel;
	while (i < g_img.rsl[0] + ft_y(g_img.rsl[1] - 1))
		g_mlx_str[i++] = g_info.flr;
}

void	ft_ply_init(void)
{
	int		i;
	int		j;

	i = 0;
	while (g_map[i] != NULL)
	{
		if (g_map[i][j] != 0 && ft_is_player(g_map[i][j])
			&& !g_ply.x && !g_ply.y)
		{
			g_ply.x = j * SZ + SZ / 2;
			g_ply.y = i * SZ + SZ / 2;
			if (g_map[i][j] == 'N')
				g_ply.trn = -90;
			if (g_map[i][j] == 'E')
				g_ply.trn = 0;
			if (g_map[i][j] == 'S')
				g_ply.trn = 90;
			if (g_map[i][j] == 'W')
				g_ply.trn = 180;
			break ;
		}
		j++;
		if (g_map[i][j] == 0 && !(j = 0))
			i++;
	}
}

void	ft_init_map_draw(void)
{
	ft_draw_cel_flr();
	ft_ply_init();
	ft_rays();
}
