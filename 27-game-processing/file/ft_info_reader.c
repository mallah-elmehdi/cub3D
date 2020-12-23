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

#include "../cub3d.h"

int		ft_info_reader(char *line)
{
	ft_strtrim(&line);
	if (*line != 0)
	{
		if (*line == 'R')
			return (ft_resolution(line));
		if (*line == 'C' || *line == 'F')
			return (ft_color(line, *line));
		if ((*line == 'N' && line[1] == 'O')
		|| (*line == 'S' && line[1] == 'O')
			|| (*line == 'W' && line[1] == 'E')
			|| (*line == 'E' && line[1] == 'A')
			|| (*line == 'S' && ft_is_whitespace(line[1])))
			return (ft_texture(line));
		if (*line != '1')
			return (ft_err("ERROR\nsyntax error"));
		if (!ft_is_info_done() && *line == '1')
			return (ft_err("ERROR\ninfo first/complet the info"));
	}
	return (0);
}
