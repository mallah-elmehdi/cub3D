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

int		ft_is_texture(char **line)
{
	int a;

	a = 0;
	if (*line[0] == 'N' && *line[1] == 'O')
		a = 2;
	else if (*line[0] == 'S' && *line[1] == 'O')
		a = 2;
	else if (*line[0] == 'S' && (*line[1] == ' ' || *line[1] == 9 || *line[1] == 11))
		a = 1;
	else if (*line[0] == 'E' && *line[1] == 'A')
		a = 2;
	else if (*line[0] == 'W' && *line[1] == 'E')
		a = 2;
	while (a--)
	{
		(*line)++;
		if (!a)
			return (1);
	}
	return (0);
}

int		ft_texture(char *line)
{
	int i;
	int b;
	char *file;

	i = 0;
	if (!ft_is_texture(&line))
		return (ft_err("TEXTURE ERROR : syntax error"));
	ft_strtrim(&line);
	while (line[i])
	{
		if (line[i] == 9 || line[i] == 11 || line[i] == 32)
			return (ft_err("TEXTURE ERROR : syntax error"));
	}
	//===========//
	printf("%s", line);
	return (1);
}
