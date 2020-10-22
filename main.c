/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:30:40 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 14:47:35 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main() {

	int fd;
	char *line;
	int a;

	a = 1;
	if ((fd = open("the_map.cub", O_RDONLY)) < 0)
		return ft_err("FILE NOT FOUND");
	while (get_next_line(fd, &line)) 
	{
		ft_strtrim(&line);
		if ((line[0] == 'C' || line[0] == 'F') && a++)
			ft_color(line);
		else if (line[0] == 'R' && a++)
			ft_resolution(line);
		else
		{
			if (ft_texture(line))
				a++;
			else if (ft_strlen(line) > 0 && line[0] != '1')
				return (ft_err("SYNTX ERR"));
		}
	}
	if (a < 9)
		return (ft_err("ENTER ALL NEEDED INFOS"));
	return (ft_map_reader());
} 
