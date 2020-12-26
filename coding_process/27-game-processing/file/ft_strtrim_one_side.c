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

#include "../cub3d.h"

int		ft_strlen_trim(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (i < 0)
		return (0);
	while (i >= 0 && ft_is_whitespace(str[i]))
		i--;
	return (i);
}

void	ft_strtrim_one_side(char **line)
{
	int		len;

	len = ft_strlen_trim(*line) + 1;
	line[0][len] = 0;
}
