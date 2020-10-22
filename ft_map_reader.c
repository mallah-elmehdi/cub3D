/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:19:04 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 14:52:47 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_map_reader(void)
{
	int fd;
	char *line;

	if ((fd = open("the_map.cub", O_RDONLY)) < 0)
		return ft_err("FILE NOT FOUND");
	while (get_next_line(fd, &line))
	{
		if (ft_is_map(line))
			printf("%s\n", line);
	}
	return (1);
}

int ft_is_map(char *line)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '2' && line[i] != ' ' && 
				line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}
