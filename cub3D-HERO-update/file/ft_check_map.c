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

int		ft_check_map_border_1(void)
{
	int			j;

	j = 0;
	while (j < g_map_width)
	{
		if (g_map[0][j] != 0 && g_map[0][j] != '1'
		&& !ft_is_whitespace(g_map[0][j]))
			return (ft_err("ERROR\nmap error: invalid map"));
		if (ft_is_whitespace(g_map[0][j]) && (g_map[1][j] != '1'
		&& !ft_is_whitespace(g_map[1][j])) && g_map[1][j] != 0)
			return (ft_err("ERROR\nmap error: invalid map"));
		if (g_map[g_map_height][j] != 0 && g_map[g_map_height][j] != '1'
		&& !ft_is_whitespace(g_map[g_map_height][j]))
			return (ft_err("ERROR\nmap error: invalid map"));
		if (ft_is_whitespace(g_map[g_map_height][j])
		&& (g_map[g_map_height - 1][j] != '1'
		&& !ft_is_whitespace(g_map[g_map_height - 1][j]))
		&& g_map[g_map_height - 1][j] != 0)
			return (ft_err("ERROR\nmap error: invalid map"));
		j++;
	}
	return (0);
}

int		ft_map_check_1(int i, int j)
{
	if (g_map[i][j + 1] == 0 || ft_is_whitespace(g_map[i][j + 1]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (j >= (int)ft_strlen(g_map[i + 1]) || j >= (int)ft_strlen(g_map[i - 1]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if (g_map[i + 1][j] == 0 || ft_is_whitespace(g_map[i + 1][j]))
		return (ft_err("ERROR\nmap error: invalid map"));
	if ((g_map[i][j - 1] == 0 || ft_is_whitespace(g_map[i][j - 1])))
		return (ft_err("ERROR\nmap error: invalid map"));
	return (0);
}

int		ft_map_check_3(int i, int j)
{
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

	i = 1;
	while (i + 1 < g_map_height)
	{
		j = 1;
		while (g_map[i][j] != 0)
		{
			if (g_map[i][j] == '2')
				g_hm_spt++;
			if ((g_map[i][j] == '0' || g_map[i][j] == '2'
			|| ft_is_player(g_map[i][j])) && ft_map_check_1(i, j))
				return (ERR);
			if (ft_is_whitespace(g_map[i][j]) && ft_map_check_3(i, j))
				return (ERR);
			j++;
		}
		i++;
	}
	return (0);
}
