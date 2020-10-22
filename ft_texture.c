/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:41:52 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 11:17:30 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture_check(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	if (line[0] == 'S' && line[1] == 'O')
		return (1);
	if (line[0] == 'S' && line[1] != 'O')
		return (1);
	if (line[0] == 'E' && line[1] == 'A')
		return (1);
	if (line[0] == 'W' && line[1] == 'E')
		return (1);
	return (0);
}

int		ft_texture(char *line)
{
	int i;
	int b;
	char *file;

	i = 2;
	if (!ft_texture_check(line))
		return (0);
	if (line[1] == ' ')
		i = 1;
	b = ft_strlen(line);
	while (line[i] != 0 && line[i] == ' ') 
		i++;
	file = (char *)ft_calloc(sizeof(char), b - i + 1);
	b = 0;
	while (line[i] != 0)
	{
		if (line[i] == ' ')
			return (ft_err("texture SYNTAX ERROR"));
		file[b++] = line[i++];
	}
	return (1);
}
