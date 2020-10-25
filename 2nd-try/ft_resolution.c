/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:27:35 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 11:57:17 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_dimension(char line, int *i)
{
	int dim;

	dim = 0;
	while (line[*i] != 0 && line[*i] >= 48 && line[*i] <= 57 && dim <= 5121)
	{
		dim = (dim * 10) + (line[*i] - 48);
		*i = *i + 1;
	}
	return (dim);
}

int		ft_resolution_check(char *line)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ')
		{
			if (line[i] == 'R')
				a++;
			else if (!(line[i] >= 48 && line[i] <= 57))
				return (ft_err("ERROR RESOLUTION: syntax error"));
		}
		i++;
	}
	if (a > 1)
		return (ft_err("ERROR RESOLUTION: syntax error"));
	return (1);
}

int 	ft_resolution(char *line)
{
	int x; 
	int y;
	int i;

	x = -1;
	y = -1;
	i = 0;
	if (ft_resolution_check(line) == -1)
		return (-1);
	while (line[i] != 0)
	{
		if (line[i] >= 48 && line[i] <= 57 && x == -1)
			x = ft_get_dimension(line, &i);
		else if (line[i] >= 48 && line[i] <= 57 && y == -1)
			y = ft_get_dimension(line, &i);
		else if (line[i] >= 48 && line[i] <= 57 && y > -1 && x > -1)
			return (ft_err("ERROR RESOLUTION: syntax error"))
		i++;
	}
	if (x > 5120 || y > 2880)
		return (ft_err("ERROR RESOLUTION: you exceed the built in Retina display (5120 x 2880)"));
	if (x == -1 || y == -1)
		return (ft_err("ERROR RESOLUTION: missing required information (x or y)"));
	return (1);
}
