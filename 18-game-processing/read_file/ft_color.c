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

#include "../cub3d.h"

int		ft_color_syntax(char *line)
{
	int		i;

	i = 2;
	if (!ft_is_whitespace(line[1]))
		return (ft_err("ERROR\ncolor error: syntax error"));
	while (line[i] != 0)
	{
		if (!ft_is_int(line[i]) && !ft_is_whitespace(line[i]) && line[i] != ',')
			return (ft_err("ERROR\ncolor error: syntax error"));
		i++;
	}
	return (0);
}

int		ft_color_errors(char **rgb)
{
	int		i;
	int		j;

	i = 0;
	if (rgb[3] != NULL)
		return (ft_err("ERROR\ncolor error: syntax error"));
	rgb[0][0] = ' ';
	while (rgb[i] != NULL)
	{
		j = 1;
		ft_strtrim(&rgb[i]);
		if (rgb[i][0] == 0)
			return (ft_err("ERROR\ncolor error: syntax error"));
		while (rgb[i][j] != 0)
		{
			if (!ft_is_int(rgb[i][j]))
				return (ft_err("ERROR\ncolor error: syntax error"));
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_color(char *line, char c)
{
	int		color;
	char	**rgb;

	if (ft_color_syntax(line))
		return (ERR);
	rgb = ft_split(line, ',');
	if (ft_color_errors(rgb))
		return (ERR);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
		return (ft_err("ERROR\ncolor error: you exceed the limit value '255'"));
	color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_it_double(rgb, 2);
	if (c == 'C' && g_info.cel == -1)
		g_info.cel = color;
	else if (c == 'F' && g_info.flr == -1)
		g_info.flr = color;
	else
		return (ft_err("ERROR\ncolor error: doubled argument"));
	return (0);
}
