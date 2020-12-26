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
	ft_strtrim(&line);
	if (*line != 0)
	{
		if (*line == 'R')
			return (ft_resolution(line, fill_infos));
		if (*line == 'C' || *line == 'F')
			return (ft_color(line, fill_infos, *line));
		if ((*line == 'N' && line[1] == 'O') || (*line == 'S' && line[1] == 'O')
			|| (*line == 'W' && line[1] == 'E') || (*line == 'E' && line[1] == 'A') 
			|| (*line == 'S' && line[1] == ' '))
			return (ft_texture(line, fill_infos));
		if (*line != '1')
			return (ft_err("ERROR: syntax error"));
		if (!ft_is_info_done(fill_infos) && *line == '1')
			return (ft_err("ERROR: info first/needed more info"));
	}
	return (0);
}
