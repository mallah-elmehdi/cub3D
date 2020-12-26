/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:13:24 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 12:13:36 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_color_check(char *line)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 0;
	b = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ')
		{
			if (line[i] == 'C' || line[i] == 'F')
				a++;
			else (line[i] == ',')
				b++;
			else if (!(line[i] >= 48 && line[i] <= 57))
				return (ft_err("ERROR COLOR: syntax error"));
		}
		i++;
	}
	if (a > 1 || b > 2)
		return (ft_err("ERROR COLOR: syntax error"));
	return (1);
}

int		ft_color(char *line)
{
	int i;
	int j;
	char **rgb;

	i = 0;
	j = 0;
	if (ft_color_check(line) == -1)
		return (-1);
	rgb = ft_split(line, ',');
	while (rgb[i] != NULL)
	{
		while (rgb[i][j] != 0)
		{
			if (!(rgb[i][j] >= 48 && rgb[i][j] <= 57))
				rgb[i][j++] = ' ';
		}
		i++;
	}
	the_color(rgb);
	return (1);
}

int		the_color(char **rgb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (rgb[i] != NULL)
	{
		ft_strtrim(&rgb[i]);
		while (rgb[i][j] != 0)
		{
			if (!(rgb[i][j] >= 48 && rgb[i][j] <= 57))
				return (ft_err("COLOR ERROR: syntax error"));
			j++;
		}
		i++;
	}
	i = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	if (i > 16777215)
		return (ft_err("COLOR ERROR: you exceed the limit value"));
	return (i);
}
