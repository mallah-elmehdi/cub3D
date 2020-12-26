/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:19:04 by emallah           #+#    #+#             */
/*   Updated: 2020/10/23 12:12:11 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_map_reader(void)
{
	int fd;
	char *line;
	int a;
	int b;
	int c;

	b = 0;
	a = 0;
	if ((fd = open("the_map.cub", O_RDONLY)) < 0)
		return ft_err("FILE NOT FOUND");
	while ((c = get_next_line(fd, &line)))
	{
		ft_strtrim_one_side(&line);
		if (line[0] != '\0')
			a += 1;
		if (ft_is_map(line, a, &b) < 0)
			return (-1);
	}
	if (!c && !b)
		return (ft_err("333 THE MAP IS INCORRECT"));
	printf("%s---->%d", "all good", b);
	return (1);
}

int ft_is_map(char *line, int a, int *b)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	if (ft_check_border(line, a, b) < 0)
		return (-1);
	while (line[i] != 0)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
				&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E' && line[i] != 'N')
			return (0);
		i++;
	}
	return (1);
}

int ft_check_border(char *line, int a, int *b)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (a == 1 && line[i] != 0)
	{
		if (line[i] != '1')
			return (ft_err("1111 THE MAP IS INCORRECT"));
		i++;
	}
	if (a != 1)
	{
		if (line[i] != '1' || line[ft_strlen(line) - 1] != '1')
			return (ft_err("2222 THE MAP IS INCORRECT"));
		while (line[i] != 0)
		{
			if (line[i] != '1')
			{
				*b = 0;
				break ;
			}
			else
				*b = 1;
			i++;
		}
	}
	return (1);
}
