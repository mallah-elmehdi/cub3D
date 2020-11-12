/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:58:20 by emallah           #+#    #+#             */
/*   Updated: 2020/11/03 18:58:23 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_int(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	free_it(char **s)
{
	free(*s);
	*s = NULL;
}

void	free_it_double(char **s, int counter)
{
	while (counter > 0)
	{
		free(s[counter]);
		s[counter--] = NULL;
	}
	free(s);
	s = NULL;
}

void	ft_initilisation(char *file)
{
	g_infos.resolution[0] = -1;
	g_infos.resolution[1] = -1;
	g_infos.floor = -1;
	g_infos.ceilling = -1;
	g_infos.s_texture = NULL;
	g_infos.so_texture = NULL;
	g_infos.no_texture = NULL;
	g_infos.we_texture = NULL;
	g_infos.ea_texture = NULL;
	g_map_start = 1;
	g_map_width = 0;
	g_map_height = 0;
	g_file_name = file;
}

int		ft_is_info_done(void)
{
	if (g_infos.resolution[0] == -1 && g_infos.resolution[1] == -1)
		return (0);
	if (g_infos.floor == -1)
		return (0);
	if (g_infos.ceilling == -1)
		return (0);
	if (g_infos.s_texture == NULL)
		return (0);
	if (g_infos.so_texture == NULL)
		return (0);
	if (g_infos.no_texture == NULL)
		return (0);
	if (g_infos.we_texture == NULL)
		return (0);
	if (g_infos.ea_texture == NULL)
		return (0);
	return (1);
}