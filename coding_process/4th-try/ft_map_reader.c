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

// int ft_map_syntax(char *line)
// {
// 	int i;
// 	static int player;

// 	i = 1;
// 	if (line[0] == 0)
// 		return (ft_err("MAP ERROR: syntax error"));
// 	while (line[i] == ' ')
// 		i++;
// 	while (line[i] != 0)
// 	{
// 		if (line[i] != '1' || line[i] != '1' || line[i] != '2' || !ft_is_player(line[i]))
// 			return (ft_err("MAP ERROR: syntax error"));
// 		if (ft_is_player(line[i]))
// 			player++;
// 	}
// 	if (player != 1)
// 		return (ft_err("MAP ERROR: player error"));
// 	return (1);
// }

void ft_map_realloc(int **map)
{
	int matrix;
	int array;
	int i;
	int j;
	int **holder;

	i = 0;
	matrix = ft_matrix_lenght(map);
	printf("eeeee%d\n", matrix);
	holder = (int **)malloc(sizeof(int*) * (matrix + 1));
	while (i < matrix)
	{
		j = 0;
		array = ft_array_lenght(map[i]);
		holder[i] = (int *)malloc(sizeof(int) * array);
		while (j < array)
		{
			holder[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	free_it_double_int(map, ft_matrix_lenght(map) - 1);
	map = holder;
}

void ft_map_fill(char *line, int **map)
{
	int matrix;
	int i;

	matrix = ft_matrix_lenght(map) - 1;
	map[matrix] = (int *)malloc(sizeof(int) * ft_strlen(line));
	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '0')
			map[matrix][i] = 0;
		else if (line[i] == '1')
			map[matrix][i] = 1;
		else if (line[i] == '2')
			map[matrix][i] = 2;
		else if (line[i] == 'W')
			map[matrix][i] = 3;
		else if (line[i] == 'E')
			map[matrix][i] = 4;
		else if (line[i] == 'S')
			map[matrix][i] = 5;
		else if (line[i] == 'N')
			map[matrix][i] = 6;
		else if (line[i] == ' ')
			map[matrix][i] = 7;
		else
			map[matrix][i] = 8;
		i++;
	}
}

int ft_map_reader(char *line, int **map)
{
	int i;

	i = 0;
	ft_strtrim_one_side(&line);
	// if (ft_map_syntax(line) == ERR)
	// 	return (ERR);
	ft_map_realloc(map);
	ft_map_fill(line, map);
	return (1);
}

// int ft_check_border(char *line, int a, int *b)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] == ' ')
// 		i++;
// 	while (a == 1 && line[i] != 0)
// 	{
// 		if (line[i] != '1')
// 			return (ft_err("1111 THE MAP IS INCORRECT"));
// 		i++;
// 	}
// 	if (a != 1)
// 	{
// 		if (line[i] != '1' || line[ft_strlen(line) - 1] != '1')
// 			return (ft_err("2222 THE MAP IS INCORRECT"));
// 		while (line[i] != 0)
// 		{
// 			if (line[i] != '1')
// 			{
// 				*b = 0;
// 				break;
// 			}
// 			else
// 				*b = 1;
// 			i++;
// 		}
// 	}
// 	return (1);
// }
