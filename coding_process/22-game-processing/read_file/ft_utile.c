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

#include "../cub3d.h"

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
	g_info.rsl[0] = -1;
	g_info.rsl[1] = -1;
	g_info.flr = -1;
	g_info.cel = -1;
	g_map_start = 1;
	g_file_name = file;
}

int		ft_is_info_done(void)
{
	if (g_info.rsl[0] == -1 && g_info.rsl[1] == -1)
		return (0);
	if (g_info.flr == -1)
		return (0);
	if (g_info.cel == -1)
		return (0);
	if (g_info.s_txt == NULL)
		return (0);
	if (g_info.so_txt == NULL)
		return (0);
	if (g_info.no_txt == NULL)
		return (0);
	if (g_info.we_txt == NULL)
		return (0);
	if (g_info.ea_txt == NULL)
		return (0);
	return (1);
}
