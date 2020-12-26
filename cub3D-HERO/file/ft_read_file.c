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

#include "../cub3d.h"

int		ft_read_info(void)
{
	int		fd;
	char	*line;

	if ((fd = open(g_file_name, O_RDONLY)) == ERR)
		return (ft_err("ERROR\nfile error: file not found"));
	while ((g_gnl = get_next_line(fd, &line)))
	{
		if (ft_info_reader(&line))
			return (ERR);
		if (!ft_is_info_done())
			g_map_start++;
		free_it(&line);
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
		return (ft_err("ERROR\nfile error: file not found"));
	while ((g_gnl = get_next_line(fd, &line)))
	{
		if (start == g_map_start)
		{
			if (ft_map_reader(line))
			{
				free_it(&line);
				return (ERR);
			}
		}
		else
			start++;
		free_it(&line);
		if (g_gnl == 2)
			break ;
	}
	return (0);
}

int		ft_read_file(void)
{
	if (ft_read_info())
		return (ERR);
	if (ft_height_width_map())
		return (ERR);
	if (!g_map_height ||
	!(g_map = (char **)malloc(sizeof(char *) * (g_map_height + 1))))
		return (ft_err("ERROR\nmap error: no map in the file"));
	g_map[g_map_height] = NULL;
	if (ft_read_map())
		return (ERR);
	return (0);
}
