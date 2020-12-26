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

// void			render_spt(int x, int y, int sp_size, int k)
// {
// 	int			color;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	color = 0;
// 	while (i++ < sp_size)
// 	{
// 		if (x + i < 0 || x + i > g_data.width)
// 			continue;
// 		if (g_s_data[k].distance >= g_ray_distance[x + i])
// 			continue;
// 		j = 0;
// 		while (j++ < sp_size)
// 		{
// 			if ((int)(g_sprite.height * (j * g_sprite.width / sp_size) +
// 			(i * g_sprite.height / sp_size)) < g_sprite.width * g_sprite.height)
// 				color = g_sprite.data[(int)(g_sprite.height *
// 				(j * g_sprite.width / sp_size) +
// 				(i * g_sprite.height / sp_size))];
// 			if (color != 0)
// 				ft_pixel_put(x + i, y + j, color);
// 		}
// 	}
// }

// void			ft_sprite(int i)
// {
// 	float		sp_size;
// 	float		x_inter;
// 	float		y_inter;
// 	float		sp_angle;

// 	sp_angle = atan2(g_s_data[i].y - g_player.y, g_s_data[i].x - g_player.x);
// 	while (sp_angle - g_player.dirangle > M_PI)
// 		sp_angle -= 2 * M_PI;
// 	while (sp_angle - g_player.dirangle < -M_PI)
// 		sp_angle += 2 * M_PI;
// 	if (g_data.height > g_data.width)
// 		sp_size = (g_data.height / g_s_data[i].distance) * TILE_SIZE;
// 	else
// 		sp_size = (g_data.width / g_s_data[i].distance) * TILE_SIZE;
// 	y_inter = g_data.height / 2 - sp_size / 2;
// 	x_inter = (sp_angle - g_player.dirangle) /
// 	g_player.fov * g_data.width + (g_data.width / 2 - sp_size / 2);
// 	render_spt(x_inter, y_inter, sp_size, i);
// }

// void			ft_sort_sprites(void)
// {
// 	int			i;
// 	int			j;
// 	t_spt		temp;	
// 	i = 0;
// 	while (i < g_hm_spt)
// 	{
// 		j = 0;
// 		while (j < g_hm_spt - 1)
// 		{
// 			if (g_spt_s[j].lgt < g_spt_s[j + 1].lgt)
// 			{
// 				temp = g_spt_s[j];
// 				g_spt_s[j] = g_spt_s[j + 1];
// 				g_spt_s[j + 1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }


int		ft_has_spt(int i, int j, float lgt)
{
	int a;

	a = 0;
	while (a < g_spt_cnt)
	{
		if (g_spt_s[a].i == i && g_spt_s[a].j == j)
		{
			if (g_spt_s[a].lgt < lgt)
				g_spt_s[a].lgt = lgt;
			return (1);
		}
		a++;
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
		if (g_spt_s[i].lgt < g_spt_s[i + 1].lgt)
		{
			hold = g_spt_s[i];
			g_spt_s[i] = g_spt_s[i + 1];
			g_spt_s[i + 1] = hold;
			i = -1;
		}
		i++;
	}
}

int		ft_is_spt(float x, float y, int v, int start)
{
	int		i;
	int		j;
	float	lgt;

	i = ((int)y / SZ) > g_map_height ? g_map_height : (y / SZ);
	j = ((int)x / SZ) > g_map_width ? g_map_width : (x / SZ);
	i *= i < 0 ? 0 : 1;
	j *= j < 0 ? 0 : 1;
	if (g_map[i][j] == '2')
	{
		lgt = sqrt(pow((x - g_ply.x), 2) + pow((y - g_ply.y), 2));
		if (!ft_has_spt(i, j, lgt))
		{
			g_spt_s[g_spt_cnt].i = i;
			g_spt_s[g_spt_cnt].j = j;
			g_spt_s[g_spt_cnt].x = start;
			g_spt_s[g_spt_cnt].lgt = lgt;
			g_spt_s[g_spt_cnt].v = v;
			return (1);
		}
	}
	return (0);
}	

void	ft_spt_utile(void)
{
	int i;
	int s_x;

	i = 0;
	while (i < g_spt_cnt)
	{
		g_spt_s[i].ln_h = (SZ / g_spt_s[i].lgt) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
		g_spt_s[i].scl = g_spt_s[i].ln_h / SZ; 
		g_spt_s[i].y = ((float)g_img.rsl[1] - 1) / 2 - (g_spt_s[i].ln_h / 2);
		g_spt_s[i].s_y = 0;
		g_spt_s[i].s_x = 0;
		if (g_spt_s[i].y < 0)
		{
			g_spt_s[i].s_y = -g_spt_s[i].y / g_spt_s[i].scl + 1;
			g_spt_s[i].y = 0;
			g_spt_s[i].ln_h = g_img.rsl[1];
		}
		s_x = g_spt_s[i].v ? (int)g_spt_s[i].y % SZ : (int)g_spt_s[i].x % SZ;
		g_spt_s[i].s_x = s_x < g_spt_s[i].s_x ? s_x : g_spt_s[i].s_x;
		i++;
	}	
}

void	ft_draw_spt(void)
{
	int i; 
	int x;
	int y;
	int s_x;
	int m_x;

	i = 0;
	ft_spt_utile();
	ft_sort_spt();
	while (i < g_spt_cnt)
	{
		s_x = g_spt_s[i].s_x;
		m_x = g_spt_s[i].x;
		// printf("%f\n", g_spt_s[i].scl);
		while (g_spt_s[i].s_y < SZ && g_spt_s[i].y < g_img.rsl[1])
		{
			g_spt_s[i].s_x = s_x;
			g_spt_s[i].x = m_x;
			while (g_spt_s[i].s_x < SZ && g_spt_s[i].x < g_img.rsl[0])
			{
				y = 0;
				while (y < g_spt_s[i].scl)
				{
					x = 0;
					while (x < g_spt_s[i].scl)
					{
						if (g_txt.g_s[g_spt_s[i].s_y * SZ + g_spt_s[i].s_x] != 0x46332d)
							g_mlx_str[g_spt_s[i].x + x + ft_y(g_spt_s[i].y + y)] = g_txt.g_s[g_spt_s[i].s_y * SZ + g_spt_s[i].s_x];
						x++;
					}
					y++;
				}
				g_spt_s[i].s_x++;
				g_spt_s[i].x += g_spt_s[i].scl;
			}
			g_spt_s[i].y += g_spt_s[i].scl;
			g_spt_s[i].s_y++;
		}
		i++;
	}
}