/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:17:10 by emallah           #+#    #+#             */
/*   Updated: 2020/11/03 19:17:13 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_read_info(struct s_the_infos *fill_infos)
{
	int		fd;
	char	*line;

	if ((fd = open(g_file_name, O_RDONLY)) == ERR)
		return (ft_err("ERROR\nfile error: invalid file name / file not found"));
	while ((g_gnl = get_next_line(fd, &line)))
	{
		if (ft_info_reader(line, fill_infos))
			return (ERR);
		if (!ft_is_info_done(fill_infos))
			g_map_start++;
		if (g_gnl == 2)
			break ;
	}
	return (0);
}

int		ft_read_map(void)
{
	int		fd;
	int		start;
	char	*line;

	start = 0;
	if ((fd = open(g_file_name, O_RDONLY)) == ERR)
		return (ft_err("ERROR\nfile error: invalid file name / file not found"));
	while ((g_gnl = get_next_line(fd, &line)))
	{
		if (start == g_map_start)
		{
			if (ft_map_reader(line))
				return (ERR);
		}
		else
			start++;
		if (g_gnl == 2)
			break ;
	}
	return (0);
}

int		ft_read_file(struct s_the_infos *fill_infos)
{
	if (ft_read_info(fill_infos))
		return (ERR);
	if (ft_height_width_map())
		return (ERR);
	g_map = (char **)malloc(sizeof(char *) * (g_map_height + 1));
	g_map[g_map_height] = NULL;
	if (ft_read_map())
		return (ERR);
	return (0);
}
