/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:13:24 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 10:11:51 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_color(char *line)
{
	int i;
	int b;
	char *file;

	i = 1;
	b = ft_strlen(line);
	while (line[i] != 0 && line[i] == ' ')
		i++;
	file = (char *)ft_calloc(sizeof(char), b - i + 1);
	b = 0;
	while (line[i] != 0)
		file[b++] = line[i++];
	return (the_color(file));
}

int		the_color(char *file)
{
	int i;
	char **rgb;

	i = 0;
	while (file[i] != 0)
	{
		if (file[i] != ',' && (file[i] > 57  && file[i] < 48))
			return (ft_err("color SYNTAX ERROR"));
		i++;
	}
	rgb = ft_split(file, ',');
	free_it(&file);
	if (rgb[3] != NULL)
		return (ft_err("TOO MANY ARGUMENTS RGB"));
	i = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	free_it(rgb);
	return (i);
}
