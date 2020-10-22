/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:27:35 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 10:11:08 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	ft_resolution(char *line)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = -1;
	if (ft_check_synx(line))
		return (ft_err("resolution SYNTX ERROR"));
	while (line[i] != 0)
	{
		while (line[i] >= 48 && line[i] <= 57 && y == -1)
		{
			x = (x * 10) + (line[i++] - 48);
			if (line[i] == ' ')
				y = 0;
		}
		while (line[i] >= 48 && line[i] <= 57)
			y = (y * 10) + (line[i++] - 48);
		i++;
	}
	if (x > 5120 || y > 2880)
		return (ft_err("ERROR : Built-in Retina Display is (5120 x 2880)"));
	return (1);
}

int		ft_check_synx(char *line)
{
	int a;
	int i;

	a = 0;
	i = 0;
	while(line[i] != 0)
	{
		if (!(line[i] == 'R' || (line[i] >= 48 && line[i] <= 57) || line[i] == ' '))
			return (1);
		if (line[i] >= 48 && line[i] <= 57) 
		{
			a++;
			while (line[i] >= 48 && line[i] <= 57)
				i++;
		}
		i++;
	}
	if (a > 2)
		return (1);
	return (0);
}
