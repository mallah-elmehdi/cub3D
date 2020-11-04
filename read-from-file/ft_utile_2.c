/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:57:10 by emallah           #+#    #+#             */
/*   Updated: 2020/11/03 18:57:14 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_player(char c)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		return (1);
	return (0);
}

int		ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		ft_is_map(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	return (0);
}

int		ft_height_width_map(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if ((fd = open(g_file_name, O_RDONLY)) == ERR)
		return (ft_err("ERROR: file error"));
	while ((g_gnl = get_next_line(fd, &line)))
	{
		ft_strtrim_one_side(&line);
		while (line[i] != 0 && ft_is_whitespace(line[i]))
			i++;
		if (line[i] == 0 || ft_is_map(line[i]))
			g_map_height++;
		if (g_map_width < (int)ft_strlen(line))
			g_map_width = ft_strlen(line);
		if (g_gnl == 2)
			break ;
	}
	return (0);
}
