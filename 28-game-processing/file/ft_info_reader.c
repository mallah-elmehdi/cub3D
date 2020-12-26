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

int		ft_info_reader(char **line)
{
	ft_strtrim(line);
	if (*line[0] != 0)
	{
		if (*line[0] == 'R')
			return (ft_resolution(line[0]));
		if (*line[0] == 'C' || *line[0] == 'F')
			return (ft_color(line[0], *line[0]));
		if ((*line[0] == 'N' && line[0][1] == 'O')
		|| (*line[0] == 'S' && line[0][1] == 'O')
			|| (*line[0] == 'W' && line[0][1] == 'E')
			|| (*line[0] == 'E' && line[0][1] == 'A')
			|| (*line[0] == 'S' && ft_is_whitespace(line[0][1])))
			return (ft_texture(line[0]));
		if (*line[0] != '1')
			return (ft_err("ERROR\nsyntax error"));
		if (!ft_is_info_done() && *line[0] == '1')
			return (ft_err("ERROR\ninfo first/complet the info"));
	}
	return (0);
}
