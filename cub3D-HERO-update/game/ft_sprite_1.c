/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:42:03 by emallah           #+#    #+#             */
/*   Updated: 2020/12/23 14:42:06 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort_spt(void)
{
	int		i;
	t_spt	hold;

	i = 0;
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
	while (i < g_map_height)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (g_map[i][j] == '2')
			{
				g_spt_s[a].m_x = (SZ * j) + (SZ / 2);
				g_spt_s[a].m_y = (SZ * i) + (SZ / 2);
				g_spt_s[a].dr = 0;
				a++;
			}
			j++;
		}
		i++;
	}
}

float	ft_spt_agl(float x, float y, int *a)
{
	float agl;

	agl = ft_atan(y / x) - g_ply.trn;
	if (x < 0)
		agl += 180;
	*a = 1;
	if (agl < 0 && (*a = -1))
		agl *= -1;
	if (agl >= 330)
		agl -= 360;
	return (agl);
}

void	ft_spt_utile(int i, int x, int a)
{
	int b;

	b = 0;
	if (g_spt_s[i].agl <= 30)
	{
		g_spt_s[i].dr = 1;
		g_spt_s[i].st = SZ / 2;
		g_spt_s[i].w_x = g_img.rsl[0] / 2 + (a * x);
	}
	else if (g_spt_s[i].agl < 90)
	{
		b = ((x - (g_info.rsl[0] / 2)) * (SZ / g_spt_s[i].ln_h));
		b = b < 0 ? -b : b;
		if (b > SZ / 2)
			g_spt_s[i].dr = 0;
		else if ((g_spt_s[i].dr = 1))
			g_spt_s[i].st = SZ / 2 - (a * b);
		g_spt_s[i].w_x = (a < 0) ? 0 : g_info.rsl[0] - 1;
	}
}
