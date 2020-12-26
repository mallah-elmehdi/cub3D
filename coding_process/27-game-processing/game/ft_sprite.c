/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:06:21 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 20:06:23 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort_spt(void)
{
	int		i;

	i = 0;
	t_spt hold;
	while (i < g_hm_spt - 1)
	{
		if (g_spt_s[i].ray < g_spt_s[i + 1].ray)
		{
			hold = g_spt_s[i];
			g_spt_s[i] = g_spt_s[i + 1];
			g_spt_s[i + 1] = hold;
			i = -1;
		}
		i++;
	}
}

void	ft_spt(void)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	a = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (g_map[i][j] == '2')
			{
				g_spt_s[a].m_x = (SZ * j) + (SZ / 2);
				g_spt_s[a].m_y = (SZ * i) + (SZ / 2);
				g_spt_s[a].dr = 0;
				g_spt_s[a].st = SZ / 2;
				a++;
			}
			j++;
		}
		i++;
	}
}

int		ft_has_spt(int x, int y)
{
	int		a;

	a = 0;
	while (a < g_hm_spt)
	{
		if (!g_spt_s[a].dr && g_spt_s[a].m_x == x && g_spt_s[a].m_y == y)
		{
			g_spt = a;
			g_spt_s[a].dr = 1;
			return (1);
		}
		a++;
	}
	return (0);
}

void	ft_is_spt(int x, int y)
{
	int		i;
	int		j;

	i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
	j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
	i *= i < 0 ? 0 : 1;
	j *= j < 0 ? 0 : 1;
	if (g_map[i][j] == '2')
	{
		if (ft_has_spt((j * SZ) + SZ / 2, (i * SZ) + SZ / 2))
		{
			g_spt_s[g_spt].ray = sqrt(pow((g_spt_s[g_spt].m_x - g_ply.x), 2) + pow((g_spt_s[g_spt].m_y - g_ply.y), 2));
			g_spt_s[g_spt].dr = g_spt_s[g_spt].ray < SZ ? 0 : g_spt_s[g_spt].dr;
			g_spt_s[g_spt].ln_h = (SZ / g_spt_s[g_spt].ray) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
			g_spt_s[g_spt].w_y = ((float)g_img.rsl[1] - 1) / 2 - (g_spt_s[g_spt].ln_h / 2);
			g_spt_s[g_spt].w_y = (g_spt_s[g_spt].w_y < 0) ? 0 : g_spt_s[g_spt].w_y;
			g_spt_s[g_spt].w_x = g_gnl;
			g_spt_s[g_spt].st = g_gnl ? SZ / 2 :  g_spt_s[g_spt].st + (2 * W_S);
			g_spt_s[g_spt].t_x = 0;
			g_spt_s[g_spt].t_y = 0;
		}
	}
}

void	ft_draw_spt(void)
{
	int		ln_h;
	int		w_x;
	int		i;
	int		x;

	i = 0;
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
				x = 0;
				g_spt_s[i].w_x = w_x;
				while (g_spt_s[i].w_x < g_info.rsl[0] - 1)
				{
					g_spt_s[i].t_x = g_spt_s[i].st + x * (SZ / g_spt_s[i].ln_h);
					if (g_spt_s[i].t_x >= SZ) break;
					if (g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] < 0x90b490)
						g_mlx_str[g_spt_s[i].w_x + ft_y(g_spt_s[i].w_y)] = g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x];
					g_spt_s[i].w_x++;
					x++;
				}
				x = 0;
				g_spt_s[i].w_x = w_x;
				while (g_spt_s[i].w_x > 0 && g_spt_s[i].t_x > 0)
				{
					g_spt_s[i].t_x = g_spt_s[i].st + x * (SZ / g_spt_s[i].ln_h);
					if (g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x] < 0x90b490)
						g_mlx_str[g_spt_s[i].w_x + ft_y(g_spt_s[i].w_y)] = g_txt.g_s[g_spt_s[i].t_y * SZ + g_spt_s[i].t_x];
					g_spt_s[i].w_x--;
					x--;
				}
				g_spt_s[i].w_y++;
				ln_h--;
			}
		}
		i++;
	}
}
