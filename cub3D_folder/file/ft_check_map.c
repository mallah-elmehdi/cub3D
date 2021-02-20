/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:20:50 by emallah           #+#    #+#             */
/*   Updated: 2020/11/04 10:20:52 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_map_check_1(int i, int j)
{
	if (i == 0 || i == g_map_height || j == 0 || j == g_map_width - 1)
		return (ft_err("ERROR\nmap error: invalid map"));
	if (!g_map[i - 1][j] || ft_is_whitespace(g_map[i - 1][j]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (!g_map[i + 1][j] || ft_is_whitespace(g_map[i + 1][j]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if ((!g_map[i][j + 1] || ft_is_whitespace(g_map[i][j + 1])))
		return (ft_err("ERROR\nmap error: invalid map"));
	if ((!g_map[i][j - 1] || ft_is_whitespace(g_map[i][j - 1])))
		return (ft_err("ERROR\nmap error: invalid map"));
	return (0);
}

int		ft_map_check_2(int i, int j)
{
	if (i == 0 || i == g_map_height || j == 0 || j == g_map_height - 1)
		return (0);
	if (g_map[i][j + 1] == '0' || g_map[i][j + 1] == '2'
	|| ft_is_player(g_map[i][j + 1]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (g_map[i + 1][j] == '0' || g_map[i + 1][j] == '2'
	|| ft_is_player(g_map[i + 1][j]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (g_map[i - 1][j] == '0' || g_map[i - 1][j] == '2'
	|| ft_is_player(g_map[i - 1][j]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (g_map[i][j - 1] == '0' || g_map[i][j - 1] == '2'
	|| ft_is_player(g_map[i][j - 1]))
		return (ft_err("ERROR\nmap error: invalid map"));
	return (0);
}

int		ft_check_map(void)
{
	int		i;
	int		j;

	i = 0;
	while (i <= g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			if (g_map[i][j] == '2')
				g_hm_spt++;
			if ((g_map[i][j] == '0' || g_map[i][j] == '2'
			|| ft_is_player(g_map[i][j])) && ft_map_check_1(i, j))
				return (ERR);
			if ((ft_is_whitespace(g_map[i][j])
			|| !g_map[i][j]) && ft_map_check_2(i, j))
				return (ERR);
			j++;
		}
		i++;
	}
	return (0);
}
