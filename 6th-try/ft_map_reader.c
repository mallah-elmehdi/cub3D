/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:19:04 by emallah           #+#    #+#             */
/*   Updated: 2020/10/23 12:12:11 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_is_map_has_empty_line()
{
	int start;
	int end;
	// int i;

	start = 0;
	// i = 0;
	end = g_map_height - 1;
	while (map[start] != NULL && map[start][0] == 0)
		start++;
	while (end >= 0 && map[end][0] == 0)
		end--;
	while (start <= end)
	{
		if (map[start][0] == 0)
			return (ft_err("MAP ERROR: empty error"));
		start++;
	}
	return (1);
}

int ft_check_border(int i, int j)
{
	if (i == 0)
	{
		if (map[i][j] == '0' || ft_is_player(map[i][j]) || map[i][j] != '2')
			return (ft_err("MAP ERROR: map incorrect"));
	}
	if (map[i + 1] == NULL)
	{
		if (map[i][j] == '0' || ft_is_player(map[i][j]) || map[i][j] != '2')
			return (ft_err("MAP ERROR: map incorrect"));
	}
}

int ft_check_map()
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (i == 0 || map[i + 1] == NULL)
			{
				if (ft_check_border(i, j) == ERR)
					return (ERR);
			}
			if (map[i][j] == '0' || map[i][j] == '2' || ft_is_player(map[i][j]))
			{
				if (ft_map_check_1(i, j) == ERR)
					return (ERR);
			}
			if (map[i][j] == '1')
			{
				if (ft_map_check_2(i, j) == ERR)
					return (ERR);
			}
			if (ft_is_whitespace(map[i][j]))
			{
				if (ft_map_check_3(i, j) == ERR)
					return (ERR);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int ft_map_errors()
{
	if (ft_is_map_has_empty_line() == ERR)
		return (ERR);
	if (ft_check_map() == ERR)
		return (ERR);
	return (1);
}

int ft_map_syntax(char *line)
{
	int i;
	static int player;

	i = 0;

	while (ft_is_whitespace(line[i]))
		i++;
	while (line[i] != 0)
	{
		if (!ft_is_map(line[i]) && !ft_is_whitespace(line[i]) && !ft_is_player(line[i]))
			return (ft_err("MAP ERROR: syntax error"));
		if (ft_is_player(line[i]))
			player++;
		i++;
	}
	if (player > 1)
		return (ft_err("MAP ERROR: player error"));
	return (1);
}

int ft_map_reader(char *line)
{
	static int i;
	int j;

	j = 0;
	ft_strtrim_one_side(&line);
	if (ft_map_syntax(line) == ERR)
		return (ERR);
	if (i < g_map_height)
	{
		map[i] = (char *)ft_calloc(sizeof(char), g_map_width + 1);
		while (line[j] != 0)
		{
			map[i][j] = line[j];
			j++;
		}
		i++;
	}
	return (1);
}