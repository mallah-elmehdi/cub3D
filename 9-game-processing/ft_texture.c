/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:41:52 by emallah           #+#    #+#             */
/*   Updated: 2020/11/03 18:59:48 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture_add(char *line, struct s_the_infos *fill_infos, char *txt)
{
	int		a;

	a = 0;
	if (line[0] == 'N' && line[1] == 'O'
	&& fill_infos->no_texture == NULL && ++a)
		fill_infos->no_texture = txt;
	else if (line[0] == 'S' && line[1] == 'O'
			&& fill_infos->so_texture == NULL && ++a)
		fill_infos->so_texture = txt;
	else if (line[0] == 'S' && ft_is_whitespace(line[1])
			&& fill_infos->s_texture == NULL && ++a)
		fill_infos->s_texture = txt;
	else if (line[0] == 'E' && line[1] == 'A'
			&& fill_infos->ea_texture == NULL && ++a)
		fill_infos->ea_texture = txt;
	else if (line[0] == 'W' && line[1] == 'E'
	&& fill_infos->we_texture == NULL && ++a)
		fill_infos->we_texture = txt;
	if (a)
		return (0);
	return (ft_err("ERROR\ntexture error: doubled arguments"));
}

int		ft_texture_str(char *line, char **texture, int start)
{
	int		i;

	i = 0;
	*texture = (char *)ft_calloc(sizeof(char), ft_strlen(line) - start + 1);
	while (line[start] != 0)
	{
		if (ft_is_whitespace(line[start]))
		{
			free_it(texture);
			return (ft_err("ERROR\ntexture error: syntax error"));
		}
		texture[0][i++] = line[start++];
	}
	return (0);
}

int		ft_texture(char *line, struct s_the_infos *fill_infos)
{
	int		i;
	char	*texture;

	i = 2;
	while (line[i] != 0 && ft_is_whitespace(line[i]))
		i++;
	if (ft_texture_str(line, &texture, i))
		return (ERR);
	if (ft_texture_add(line, fill_infos, texture))
		return (ERR);
	return (0);
}
