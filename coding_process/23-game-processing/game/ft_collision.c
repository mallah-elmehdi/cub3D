/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:14:46 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:14:47 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_collision(int spd)
{
	float	x;
	float	y;
	int		add;
	int		i;
	int		j;

	add = spd > 0 ? 15 : -15;
	while (spd)
	{
		x = g_ply.x + (spd + add) * ft_cos(g_ply.trn + g_ply.dgr);
		y = g_ply.y + (spd + add) * ft_sin(g_ply.trn + g_ply.dgr);
		i = (y / SZ) > g_map_height ? g_map_height : (y / SZ);
		j = (x / SZ) > g_map_width ? g_map_width : (x / SZ);
		if (g_map[i][j] != '1' && g_map[i][j] != 0)
			return (spd);
		if (spd < 0)
			spd++;
		else
			spd--;
	}
	return (spd);
}
