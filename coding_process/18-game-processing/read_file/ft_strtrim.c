/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:06:53 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 11:51:45 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		index_front(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_is_whitespace(str[i]))
			break ;
		i++;
	}
	return (i);
}

int		index_back(char *str)
{
	int		i;

	if ((i = ft_strlen(str) - 1) < 0)
		return (0);
	while (i > 0)
	{
		if (!ft_is_whitespace(str[i]))
			break ;
		i--;
	}
	return (i);
}

void	ft_strtrim(char **line)
{
	char	*hold;
	int		i;
	int		start;
	int		len;

	i = 0;
	start = index_front(*line);
	len = index_back(*line) - start + 1;
	if (len < 0)
		len = 0;
	hold = (char*)ft_calloc(sizeof(char), len + 1);
	while (i < len)
		hold[i++] = line[0][start++];
	free_it(line);
	*line = (char*)ft_calloc(sizeof(char), len + 1);
	i = 0;
	while (hold[i] != 0)
	{
		line[0][i] = hold[i];
		i++;
	}
	free_it(&hold);
}
