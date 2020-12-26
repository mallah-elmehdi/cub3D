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

void			ft_sort_sprites(void)
{
	int			i;
	int			j;
	t_spt		temp;	
	i = 0;
	while (i < g_hm_spt)
	{
		j = 0;
		while (j < g_hm_spt - 1)
		{
			if (g_spt_s[j].lgt < g_spt_s[j + 1].lgt)
			{
				temp = g_spt_s[j];
				g_spt_s[j] = g_spt_s[j + 1];
				g_spt_s[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}


int		ft_has_spt(int i, int j, float lgt)
{
	int a;

	a = 0;
	while (a < g_spt)
	{
		if (g_spt_s[a].i == i && g_spt_s[a].j == j)
		{
			if (g_spt_s[a].lgt < lgt)
				g_spt_s[a].lgt = lgt;
			return (1);
		}
	}
	return (0);
}

void	ft_sort_spt()
{
	int i;

	i = 0;
	t_spt hold;
	while (i < g_spt - 1)
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

void	ft_draw_spt(int x, int y)
{
	int ln_h;
	int t_x;
	int t_y;
	int i;
	int j;

	i = 0;
	j = 0;
	t_y = 0;
	ft_sort_spt();
	while (i < g_spt)
	{
		ln_h = (SZ / g_spt_s[i].lgt) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
		ln_h = (ln_h > g_img.rsl[0]) ? g_img.rsl[0] : ln_h;
		g_spt_s[i].scl = (ln_h / SZ == 0) ? 1 : ln_h / SZ; 
		y = ((float)g_img.rsl[1] - 1) / 2 - (ln_h / 2);
		if (y < 0)
		{
			y *= -1;
			t_y = y % g_spt_s[i].scl;
			y = 0;
		}
		t_x = g_spt_s[i].v ? (int)g_spt_s[i].y % SZ : (int)g_spt_s[i].x % SZ;
		while (ln_h)
		{

			while (j < g_spt_s[i].scl)
			{
				g_mlx_str[x + ft_y(y)] = g_txt.g_s[t_y * SZ + t_x];
				y++;
				j++;
				ln_h--;
			}
			
		}
		
	}
	
}

int		ft_is_spt(float x, float y, int v)
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
			g_spt_s[g_spt].i = i;
			g_spt_s[g_spt].j = j;
			g_spt_s[g_spt].x = x;
			g_spt_s[g_spt].y = y;
			g_spt_s[g_spt].lgt = lgt;
			g_spt_s[g_spt].v = v;
			return (1);
		}
	}
	return (0);
}	