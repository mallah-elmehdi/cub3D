/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:13:24 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 20:42:52 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_color(char *line)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] != 9 && line[i] != 10 && line[i] != 32
				&& line[i] != ',' && !(line[i] <= 57  && line[i] >= 48))
			return (ft_err("COLOR ERROR: syntax error"));
		i++;
	}
	the_color(line);
	return (1);
}

int		the_color(char *line)
{
	int i;
	int j;
	char **rgb;

	i = 0;
	j = 0;
	ft_strtrim(&line);
	rgb = ft_split(line, ',');
	if (rgb[3] != NULL)
		return (ft_err("COLOR ERROR: too many arguments"));
	while (i < 3)
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
