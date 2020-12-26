/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:34:16 by emallah           #+#    #+#             */
/*   Updated: 2020/10/21 14:10:33 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_sprite_texture(char *line)
{
	int i;
	int b;
	char *file;

	i = 1;
	b = ft_strlen(line);
	while (line[i] != 0 && line[i] == ' ') 
		i++;
	file = (char *)ft_calloc(sizeof(char), b - i + 1);
	b = 0;
	while (line[i] != 0)
	{
		if (line[i] == ' ')
			return (ft_err("SYNTAX ERROR"));
		file[b++] = line[i++];
	}
	return (0);
}
