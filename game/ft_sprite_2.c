/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:42:17 by emallah           #+#    #+#             */
/*   Updated: 2020/12/23 14:42:19 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ft_atan(float o)
{
	return (atan(o) * 180 / PI);
}

void	ft_is_spt(void)
{
	int		i;
	int		x;
	int		a;
	float	y;

	i = 0;
	y = ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
	while (i < g_hm_spt)
	{
		g_spt_s[i].ray = sqrt(pow((g_spt_s[i].m_x - g_ply.x), 2)
		+ pow((g_spt_s[i].m_y - g_ply.y), 2));
		g_spt_s[i].ln_h = (SZ / g_spt_s[i].ray) * y;
		g_spt_s[i].w_y = ((float)g_img.rsl[1] - 1) / 2
		- (g_spt_s[i].ln_h / 2);
		g_spt_s[i].w_y = (g_spt_s[i].w_y < 0) ? 0 : g_spt_s[i].w_y;
		g_spt_s[i].agl = ft_spt_agl(g_spt_s[i].m_x
		- g_ply.x, g_spt_s[i].m_y - g_ply.y, &a);
		x = y * ft_tan(g_spt_s[i].agl);
		ft_spt_utile(i, x, a);
		i++;
	}
}

void	ft_draw_help_1(int i, int w_x)
{
	int x;

	x = 0;
	g_spt_s[i].w_x = w_x;
	while (g_spt_s[i].w_x < g_info.rsl[0])
	{
		g_spt_s[i].t_x = g_spt_s[i].st + x * (SZ / g_spt_s[i].ln_h);
		if (g_spt_s[i].t_x >= SZ)
			break ;
		if (g_spt_s[i].t_y < 0 || g_spt_s[i].t_y >= SZ)
			break ;
		if (g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] > 0
		&& g_lgst[g_spt_s[i].w_x] > g_spt_s[i].ray)
			g_mlx_str[g_spt_s[i].w_x + ft_y(g_spt_s[i].w_y)] =
			g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x];
		g_spt_s[i].w_x++;
		x++;
	}
}

void	ft_draw_help_2(int i, int w_x)
{
	int x;

	x = 0;
	g_spt_s[i].w_x = w_x;
	while (g_spt_s[i].w_x >= 0)
	{
		g_spt_s[i].t_x = g_spt_s[i].st + x * (SZ / g_spt_s[i].ln_h);
		if (g_spt_s[i].t_y < 0 || g_spt_s[i].t_y >= SZ)
			break ;
		if (g_spt_s[i].t_x < 0)
			break ;
		if (g_spt_s[i].t_y * SZ + g_spt_s[i].t_x < SZ * SZ
		&& g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] > 0
		&& g_lgst[g_spt_s[i].w_x] > g_spt_s[i].ray)
			g_mlx_str[g_spt_s[i].w_x + ft_y(g_spt_s[i].w_y)] =
			g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x];
		g_spt_s[i].w_x--;
		x--;
	}
}

void	ft_draw_spt(void)
{
	int		ln_h;
	int		w_x;
	int		i;

	i = 0;
	ft_is_spt();
	ft_sort_spt();
	while (i < g_hm_spt)
	{
		if (g_spt_s[i].dr && !(g_spt_s[i].dr = 0))
		{
			ln_h = g_spt_s[i].ln_h;
			w_x = g_spt_s[i].w_x;
			while (ln_h && g_spt_s[i].w_y < g_info.rsl[1])
			{
				g_spt_s[i].t_y = (g_spt_s[i].w_y + g_spt_s[i].ln_h / 2
				- (g_info.rsl[1] - 1) / 2) * (SZ / g_spt_s[i].ln_h);
				ft_draw_help_1(i, w_x);
				ft_draw_help_2(i, w_x);
				g_spt_s[i].w_y++;
				ln_h--;
			}
		}
		i++;
	}
}
