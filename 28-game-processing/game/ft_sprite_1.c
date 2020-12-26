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
				a++;
			}
			j++;
		}
		i++;
	}
}

// int		ft_has_spt(int x, int y)
// {
// 	int		a;

// 	a = 0;
// 	while (a < g_hm_spt)
// 	{
// 		if (!g_spt_s[a].dr && g_spt_s[a].m_x == x && g_spt_s[a].m_y == y)
// 		{
// 			g_s = a;
// 			g_spt_s[a].dr = 1;
// 			return (1);
// 		}
// 		a++;
// 	}
// 	return (0);
// }
