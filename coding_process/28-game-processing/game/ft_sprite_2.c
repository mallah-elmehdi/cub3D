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
	int		b;
	int		a;
	float	y;
	float	xx;
	float	yy;

	i = 0;
	y = ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
	while (i < g_hm_spt)
	{
		g_spt_s[i].ray = sqrt(pow((g_spt_s[i].m_x - g_ply.x), 2) + pow((g_spt_s[i].m_y - g_ply.y), 2));
		g_spt_s[i].ln_h = (SZ / g_spt_s[i].ray) * y;
		g_spt_s[i].w_y = ((float)g_img.rsl[1] - 1) / 2 - (g_spt_s[i].ln_h / 2);
		g_spt_s[i].w_y = (g_spt_s[i].w_y < 0) ? 0 : g_spt_s[i].w_y;
		xx = g_spt_s[i].m_x - g_ply.x;
		yy = g_spt_s[i].m_y - g_ply.y;
		g_spt_s[i].agl = ft_atan(yy / xx) - g_ply.trn;
		if (yy < 0 && xx < 0)
			g_spt_s[i].agl -= 180;
		else if (xx < 0)
			g_spt_s[i].agl += 180;
		a = 1;
		if (g_spt_s[i].agl < 0 && (a = -1))
			g_spt_s[i].agl *= -1;
		if (g_spt_s[i].agl >= 330)
			g_spt_s[i].agl -= 360;
		if (g_spt_s[i].agl <= 30)
		{
			x = y * ft_tan(g_spt_s[i].agl);
			g_spt_s[i].dr = 1;
			g_spt_s[i].st = SZ / 2;
			g_spt_s[i].w_x = g_img.rsl[0] / 2 + (a * x);
		}
		else if (g_spt_s[i].agl < 90)
		{
			x = y * ft_tan(g_spt_s[i].agl);
			b = ((x - (g_info.rsl[0] / 2)) * (SZ / g_spt_s[i].ln_h));
			b = b < 0 ? -b : b;
			if (b > SZ / 2)
				g_spt_s[i].dr = 0;
			else
			{
				g_spt_s[i].st = SZ / 2 - (a * b);
				g_spt_s[i].dr = 1;
			}
			if (a < 0)
				g_spt_s[i].w_x = 0;
			else
				g_spt_s[i].w_x = g_info.rsl[0] - 1;
		}
		i++;
	}
}

void	ft_draw_help_1(int i, int w_x)
{
	int x;

	x = 0;
	g_spt_s[i].w_x = w_x;
	while (g_spt_s[i].w_x < g_info.rsl[0] - 1)
	{
		g_spt_s[i].t_x = g_spt_s[i].st + x * (SZ / g_spt_s[i].ln_h);
		if (g_spt_s[i].t_x >= SZ)
			break ;
		if (g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] < 0x90b490 && g_lgst[g_spt_s[i].w_x] > g_spt_s[i].ray)
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
		if (g_spt_s[i].t_x <= 0)
			break ;
		if (g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] < 0x90b490  && g_lgst[g_spt_s[i].w_x] > g_spt_s[i].ray)
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
		if (g_spt_s[i].dr)
		{
			g_spt_s[i].dr = 0;
			ln_h = g_spt_s[i].ln_h;
			w_x = g_spt_s[i].w_x;
			while (ln_h && g_spt_s[i].w_y < (g_info.rsl[1] - 1))
			{
				g_spt_s[i].t_y = (g_spt_s[i].w_y + g_spt_s[i].ln_h / 2 - (g_info.rsl[1] - 1) / 2) * (SZ / g_spt_s[i].ln_h);
				ft_draw_help_1(i, w_x);
				ft_draw_help_2(i, w_x);
				g_spt_s[i].w_y++;
				ln_h--;
			}
		}
		i++;
	}
}
