/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:41:52 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 19:08:59 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_texture_add(char *line, struct the_infos *fill_infos, char *texture)
{
	int a;

	a = 0;
	if (line[0] == 'N' && line[1] == 'O' && fill_infos->no_texture == NULL && ++a)
		fill_infos->no_texture = texture;
	else if (line[0] == 'S' && line[1] == 'O' && fill_infos->so_texture == NULL && ++a)
		fill_infos->so_texture = texture;
	else if (line[0] == 'S' && line[1] == ' ' && fill_infos->s_texture == NULL && ++a)
		fill_infos->s_texture = texture;
	else if (line[0] == 'E' && line[1] == 'A' && fill_infos->ea_texture == NULL && ++a)
		fill_infos->ea_texture = texture;
	else if (line[0] == 'W' && line[1] == 'E' && fill_infos->we_texture == NULL && ++a)
		fill_infos->we_texture = texture;
	if (a)
		return (1);
	return (ft_err("TEXTURE ERROR: doubled arguments"));
}

int ft_texture_str(char *line, char **texture, int start)
{
	int i;

	i = 0;
	*texture = (char *)ft_calloc(sizeof(char), ft_strlen(line) - start + 1);
	while (line[start] != 0)
	{
		if (line[start] == ' ')
		{
			free_it(texture);
			return (ft_err("TEXTURE ERROR: syntax error"));
		}
		texture[0][i++] = line[start++];
	}
	return (1);
}

int ft_texture(char *line, struct the_infos *fill_infos)
{
	int i;
	char *texture;

	i = 2;
	while (line[i] != 0 && line[i] == ' ')
		i++;
	if (ft_texture_str(line, &texture, i) == ERR)
		return (ERR);
	if (ft_texture_add(line, fill_infos, texture) == ERR)
		return (ERR);
	return (1);
}
