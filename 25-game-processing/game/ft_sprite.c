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

int		ft_has_spt(float x, float y, int i, int j, int v)
{
	int a;

	a = 0;
	while (a < g_spt_cnt)
	{
		if (g_spt_s[a].i == i && g_spt_s[a].j == j)
		{
			g_spt_s[a].stop = v ? (int)y % SZ : (int)x % SZ;
			return (1);
		}
		a++;
	}
	return (0);
}

int		ft_is_spt(float x, float y, int v, int start)
{
	int		i;
	int		j;
	float	ray;

	i = ((int)y / SZ) > g_map_height ? g_map_height : (y / SZ);
	j = ((int)x / SZ) > g_map_width ? g_map_width : (x / SZ);
	i *= i < 0 ? 0 : 1;
	j *= j < 0 ? 0 : 1;
	if (g_map[i][j] == '2')
	{
		if (!ft_has_spt(x,y,i, j, v))
		{
			g_spt_s[g_spt_cnt].i = i;
			g_spt_s[g_spt_cnt].j = j;
			g_spt_s[g_spt_cnt].x = start;
// ============= Find the x in the xpm
				if (g_spt_s[g_spt_cnt].v && g_spt_s[g_spt_cnt].s_x < SZ/2 && !v)
					g_spt_s[g_spt_cnt].s_x = g_ray.r ? SZ : 0;
			else if (g_ray.d)
			{
				 if (g_ray.r)
					g_spt_s[g_spt_cnt].s_x = v ? (int)y % SZ : (int)x % SZ;
				else if (g_ray.l)
					g_spt_s[g_spt_cnt].s_x = v ? SZ - (int)y % SZ : SZ - (int)x % SZ;
			}
			else if (g_ray.u)
			{
				if (g_ray.r)
					g_spt_s[g_spt_cnt].s_x = v ?(int)y % SZ : (int)x % SZ;
				if (g_ray.l)
					g_spt_s[g_spt_cnt].s_x = v ? SZ - (int)y % SZ : (int)x % SZ;
			}

			// printf ("d=%d",g_ray.d);
			// printf ("u=%d",g_ray.u);
			// printf ("l=%d",g_ray.l);
			// printf ("r=%d",g_ray.r);


// ============= Normalize the ray
			if (v)
			{
				if (g_ray.l)
					x = (int)x - (SZ / 2);
				else
					x = (int)x + (SZ / 2);
				y += SZ / 2 - (int)y % SZ;
			}
			else
			{
				if (g_ray.u)
					y = (int)y - (SZ / 2);
				else
					y = (int)y + (SZ / 2);
				x += SZ / 2 - (int)y % SZ;
			}
			x += SZ / 2;
			y += SZ / 2;
			ray = sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2));
			g_spt_s[g_spt_cnt].ray = ray;
			g_spt_s[g_spt_cnt].v = v;
 			// printf("r = %d\n",  g_ray.r);
			return (1);
		}
	}
	return (0);
}

void	ft_sort_spt(void)
{
	int i;

	i = 0;
	t_spt hold;
	while (i < g_spt_cnt - 1)
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

void	ft_spt_utile(void)
{
	int i;

	i = 0;
	while (i < g_spt_cnt)
	{
		// g_spt_s[i].s_x = 0;
		g_spt_s[i].ln_h = (SZ / g_spt_s[i].ray) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
		g_spt_s[i].y = ((float)g_img.rsl[1] - 1) / 2 - (g_spt_s[i].ln_h / 2);
		g_spt_s[i].y = (g_spt_s[i].y < 0) ? 0 : g_spt_s[i].y;
		i++;
	}	
}

void	ft_draw_spt(void)
{
	int i;
	int ln_h;
	int ln_h_x;
	int s_x;
	int m_x;
	int x;
	int x_int;

	i = 0;
	ft_spt_utile();
	ft_sort_spt();
	while (i < g_spt_cnt)
	{
		s_x = g_spt_s[i].s_x;
		x_int = g_spt_s[i].s_x;
		m_x = g_spt_s[i].x;
		ln_h = g_spt_s[i].ln_h;

		printf("s = %d\n", g_spt_s[i].s_x);
		printf("p = %d\n", g_spt_s[i].stop);
		printf("==================\n");

		while (ln_h && g_spt_s[i].y < g_info.rsl[1] - 1)
		{
			g_spt_s[i].s_y = (g_spt_s[i].y + g_spt_s[i].ln_h / 2 - g_info.rsl[1] / 2) * (SZ / g_spt_s[i].ln_h);
			x = 0;
			g_spt_s[i].x = m_x;
			g_spt_s[i].s_x = s_x;
			ln_h_x = g_spt_s[i].ln_h;
			while (ln_h_x && g_spt_s[i].x < g_info.rsl[0] - 1)
			// while (g_spt_s[i].s_x < g_spt_s[i].stop)
			{
				g_spt_s[i].s_x = x_int + x * (SZ / g_spt_s[i].ln_h);
				if (g_spt_s[i].s_x >= SZ) break;
				if (g_txt.g_s[g_spt_s[i].s_y * SZ + g_spt_s[i].s_x] != 0x46332d)
					g_mlx_str[g_spt_s[i].x + ft_y(g_spt_s[i].y)] = g_txt.g_s[g_spt_s[i].s_y * SZ + g_spt_s[i].s_x];
				ln_h_x--;
				g_spt_s[i].x++;
				x++;
			}
			g_spt_s[i].y++;
			ln_h--;
		}
		i++;
	}
	g_spt_cnt = 0;
}