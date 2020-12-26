/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:30:40 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 10:27:35 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_skip_space(char *line)
{
	int i;

	i = 0;
	while (line[i] == 9 || line[i] == 11 || line[i] == 32)
		i++;
	return (i);
}

int main() {

	int		fd;
	char	*line;
	int		a;

	a = 0;
	if ((fd = open("the_map.cub", O_RDONLY)) < 0)
		return ft_err("ERROR: file not found");
	while (get_next_line(fd, &line) == 1) 
	{
		if (line[ft_skip_space(line)] != '1')
		{
			if (ft_info_reader(line) < 0)
				return (-1);
			a++;
		}
		else
		{
			//if (ft_map_reader(line) < 0)
				//return (-1);
			a++;
		}
		//if (a < 8)
			//return ft_err("ERROR info: syntax error");
		free_it(&line);
	}
	return (1);
} 
