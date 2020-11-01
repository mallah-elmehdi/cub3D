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

int ft_color_syntax(char *line)
{
	int i;

	i = 2;
	if (line[1] != ' ')
		return (ft_err("COLOR ERROR: syntax error"));
	while (line[i] != 0)
	{
		if (!ft_is_int(line[i]) && line[i] != ' ' && line[i] != ',')
			return (ft_err("COLOR ERROR: syntax error"));
		i++;
	}
	return (1);
}

int ft_color_errors(char **rgb)
{
	int i;
	int j;

	i = 0;
	if (rgb[3] != NULL)
		return (ft_err("COLOR ERROR: syntax error"));
	rgb[0][0] = ' ';
	while (rgb[i] != NULL)
	{
		j = 1;
		ft_strtrim(&rgb[i]);
		if (rgb[i][0] == 0)
				return (ft_err("COLOR ERROR: syntax error"));
		while (rgb[i][j] != 0)
		{
			if (!ft_is_int(rgb[i][j]))
				return (ft_err("COLOR ERROR: syntax error"));
			j++;
		}
		i++;
	}
	return (1);
}

int ft_color(char *line, struct the_infos *fill_infos, char c)
{
	int color;
	char **rgb;

	if (ft_color_syntax(line) == ERR)
		return (ERR);
	rgb = ft_split(line, ',');
	if (ft_color_errors(rgb) == ERR)
		return (ERR);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
		return (ft_err("COLOR ERROR: you exceed the limit value"));
	color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_it_double(rgb, 2);

	if (c == 'C' && fill_infos->ceilling == -1)
		fill_infos->ceilling = color;
	else if (c == 'F' && fill_infos->floor == -1)
		fill_infos->floor = color;
	else
        return (ft_err("COLOR ERROR: doubled argument"));
	return (1);
}