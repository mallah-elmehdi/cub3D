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

#include "../cub3d.h"

int		ft_texture_add(char *line, char *txt)
{
	int		a;

	a = 0;
	if (line[0] == 'N' && line[1] == 'O'
	&& g_info.no_txt == NULL && ++a)
		g_info.no_txt = txt;
	else if (line[0] == 'S' && line[1] == 'O'
			&& g_info.so_txt == NULL && ++a)
		g_info.so_txt = txt;
	else if (line[0] == 'S' && ft_is_whitespace(line[1])
			&& g_info.s_txt == NULL && ++a)
		g_info.s_txt = txt;
	else if (line[0] == 'E' && line[1] == 'A'
			&& g_info.ea_txt == NULL && ++a)
		g_info.ea_txt = txt;
	else if (line[0] == 'W' && line[1] == 'E'
	&& g_info.we_txt == NULL && ++a)
		g_info.we_txt = txt;
	if (a)
		return (0);
	return (ft_err("ERROR\ntexture error: doubled arguments"));
}

void	ft_add_mem_free(char **str)
{
	if (g_fre_mem == 0)
		g_fre.m1 = *str;
	if (g_fre_mem == 1)
		g_fre.m2 = *str;
	if (g_fre_mem == 2)
		g_fre.m3 = *str;
	if (g_fre_mem == 3)
		g_fre.m4 = *str;
	if (g_fre_mem == 4)
		g_fre.m5 = *str;
	g_fre_mem++;
}

int		ft_texture_str(char *line, char **texture, int start)
{
	int		i;

	i = 0;
	*texture = (char *)ft_calloc(sizeof(char), ft_strlen(line) - start + 1);
	ft_add_mem_free(texture);
	while (line[start] != 0)
	{
		if (ft_is_whitespace(line[start]))
		{
			free_it(texture);
			g_fre_mem--;
			ft_free_mem();
			return (ft_err("ERROR\ntexture error: syntax error"));
		}
		texture[0][i++] = line[start++];
	}
	return (0);
}

int		ft_texture(char *line)
{
	int		i;
	char	*texture;

	i = 2;
	while (line[i] != 0 && ft_is_whitespace(line[i]))
		i++;
	if (ft_texture_str(line, &texture, i))
		return (ERR);
	if (ft_texture_add(line, texture))
		return (ERR);
	return (0);
}
