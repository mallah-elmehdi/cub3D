/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:29:05 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 20:42:34 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_info_reader(char *line)
{
	while (*line != 0)
	{
		while (*line == 9 || *line == 11 || *line == 32)
			line++;
		if (*line == 'R')
			return (ft_resolution(++line));
		if (*line == 'C' || *line == 'F')
			return (ft_color(++line));
		if (*line != 0)
			//return (ft_texture(line));
			return (0);
	}
	return (1);
}
