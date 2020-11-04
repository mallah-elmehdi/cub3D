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

#include "cub3d.h"

int		ft_map_check_1(int i, int j)
{
	if (g_map[i][j + 1] == 0 || ft_is_whitespace(g_map[i][j + 1]))
		return (ft_err("MAP ERROR:4 incorrect map"));
	if (j >= (int)ft_strlen(g_map[i + 1]) || j >= (int)ft_strlen(g_map[i - 1]))
		return (ft_err("MAP ERROR:5 incorrect map"));
	if (g_map[i + 1][j] == 0 || ft_is_whitespace(g_map[i + 1][j]))
		return (ft_err("MAP ERROR:6 incorrect map"));
	if ((g_map[i][j - 1] == 0 || ft_is_whitespace(g_map[i][j - 1])))
		return (ft_err("MAP ERROR:7 incorrect map"));
	return (0);
}

// int		ft_map_check_2(int i, int j)
// {
// 	if ((g_map[i][j + 1] == 0 || ft_is_whitespace(g_map[i][j + 1]))
// 	&& (g_map[i][j - 1] == 0 || ft_is_whitespace(g_map[i][j - 1]))
// 	&& (g_map[i + 1][j] == 0 || ft_is_whitespace(g_map[i + 1][j])
// 	|| j >= (int)ft_strlen(g_map[i + 1]))
// 	&& (g_map[i - 1][j] == 0 || ft_is_whitespace(g_map[i - 1][j])
// 	|| j >= (int)ft_strlen(g_map[i - 1])))
// 		return (ft_err("MAP ERROR: incorrect map"));
// 	return (0);
// }

int		ft_map_check_3(int i, int j)
{
	if (g_map[i][j + 1] == '0' || g_map[i][j + 1] == '2'
	|| ft_is_player(g_map[i][j + 1]))
		return (ft_err("MAP ERROR:8 incorrect map"));
	if (g_map[i + 1][j] == '0' || g_map[i + 1][j] == '2'
	|| ft_is_player(g_map[i + 1][j]))
		return (ft_err("MAP ERROR:9 incorrect map"));
	if (g_map[i - 1][j] == '0' || g_map[i - 1][j] == '2'
	|| ft_is_player(g_map[i - 1][j]))
		return (ft_err("MAP ERROR:10 incorrect map"));
	if (g_map[i][j - 1] == '0' || g_map[i][j - 1] == '2'
	|| ft_is_player(g_map[i][j - 1]))
		return (ft_err("MAP ERROR:11 incorrect map"));
	return (0);
}

int		ft_check_map(void)
{
	int		i;
	int		j;

	i = 1;
	while (g_map[i + 1] != NULL)
	{
		j = 1;
		while (g_map[i][j] != 0)
		{
			if ((g_map[i][j] == '0' || g_map[i][j] == '2'
			|| ft_is_player(g_map[i][j])) && ft_map_check_1(i, j))
				return (ERR);
			if (g_map[i][j] == '1' && ft_map_check_2(i, j))
				return (ERR);
			if (ft_is_whitespace(g_map[i][j]) && ft_map_check_3(i, j))
				return (ERR);
			j++;
		}
		i++;
	}
	return (0);
}
