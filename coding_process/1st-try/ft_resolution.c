/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:27:35 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 18:55:28 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_dimension(char **line)
{
	int dim;

	dim = 0;
	while (**line != 0 && **line >= 48 && **line <= 57 && dim <= 5121)
	{
		dim = (dim * 10) + (**line - 48);
		(*line)++;
	}
	return (dim);
}

int 	ft_resolution(char *line)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (*line != 0)
	{
		while (*line == 9 || *line == 11 || *line == 32)
			line++;
		if (!(*line >= 48 && *line <= 57) || y != -1)
			return (ft_err("ERROR RESOLUTION: syntax error"));
		if (x == -1)
			x = ft_get_dimension(&line);
		else if (y == -1)
			y = ft_get_dimension(&line);
	}
	if (x > 5120 || y > 2880)
		return (ft_err("ERROR RESOLUTION: you exceed the built in Retina display (5120 x 2880)"));
	if (x == -1 || y == -1)
		return (ft_err("ERROR RESOLUTION: missing required information (x or y)"));
	return (1);
}
