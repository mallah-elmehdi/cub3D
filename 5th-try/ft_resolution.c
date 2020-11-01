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

int		ft_resolution_syntax(char *line)
{
	int		i;

	i = 2;
	if (line[1] != ' ')
		return (ft_err("RESOLUTION ERROR: syntax error"));
	while (line[i] != 0)
	{
		if (!ft_is_int(line[i]) && line[i] != ' ')
			return (ft_err("RESOLUTION ERROR: syntax error"));
		i++;
	}
	return (1);
}

int		ft_resolution_errors(char *line)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (line[i] != 0)
	{
		if (ft_is_int(line[i]))
		{
			a++;
			while (ft_is_int(line[i]))
			{
				if (!(line[i + 1] >= 48 && line[i + 1] <= 57))
					break ;
				i++;
			}
		}
		i++;
	}
	if (a != 2)
		return (ft_err("RESOLUTION ERROR: arguments error"));
	return (1);
}

void	ft_dimension(char *line, int *x, int *y)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (*x == 0)
		{
			while (ft_is_int(line[i]))
			{
				if (*x < 99999)
					*x = (*x * 10) + (line[i] - 48);
				i++;
			}
		}
		else if (*y == 0)
		{
			while (ft_is_int(line[i]))
			{
				if (*y < 99999)
					*y = (*y * 10) + (line[i] - 48);
				i++;
			}
		}
		i++;
	}
}

int		ft_resolution_add(char *line, struct the_infos *fill_infos)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	ft_dimension(line, &x, &y);
	if (x > 5120)
		x = 5120;
	if (y > 2880)
		y = 2880;
	fill_infos->resolution[0] = x;
	fill_infos->resolution[1] = y;
	return (1);
}

int		ft_resolution(char *line, struct the_infos *fill_infos)
{
	int		i;

	i = 0;
	if (fill_infos->resolution[0] != -1 && fill_infos->resolution[1] != -1)
		return (ft_err("RESOLUTION ERROR: doubled argument"));
	if (ft_resolution_syntax(line) == ERR)
		return (ERR);
	if (ft_resolution_errors(line) == ERR)
		return (ERR);
	if (ft_resolution_add(line, fill_infos) == ERR)
		return (ERR);
	if (fill_infos->resolution[0] == 0 || fill_infos->resolution[1] == 0)
		return (ft_err("RESOLUTION ERROR: creating window error"));
	return (1);
}
