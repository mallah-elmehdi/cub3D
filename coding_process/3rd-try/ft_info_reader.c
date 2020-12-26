/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:29:05 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 11:15:35 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_info_reader(char *line, struct the_infos *fill_infos)
{
	if (*line != 0)
	{
		if (line[ft_skip_space(line)] == 'R')
			return(ft_resolution(line, fill_infos));
		// if (line[i] == 'C' || line[i] == 'F')
		// 	return (ft_color(line));
		// if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i + 1] == 'O')
		// 		|| (line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'E' && line[i + 1] == 'A')
		// 		|| (line[i] == 'S' && line[i + 1] == ' '))
			// return (ft_texture(line));
	}
	return (ft_err("INFO ERROR: syntax error"));
}
