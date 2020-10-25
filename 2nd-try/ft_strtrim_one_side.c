/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_one_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:17:54 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 19:14:24 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen_trim(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (0);
	while (i >= 0 && str[i] == ' ')
		i--;
	return (i);
}

void	ft_strtrim_one_side(char **line)
{
	char	*hold;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_trim(*line);
	hold = (char*)ft_calloc(sizeof(char), len + 2);
	while (i <= len)
	{
		hold[i] = line[0][i];
		i++;
	}
	free_it(line);
	*line  = (char*)ft_calloc(sizeof(char), len + 2);
	i = 0;
	while (hold[i] != 0)
	{
		line[0][i] = hold[i];
		i++;
	}
	free_it(&hold);
}
