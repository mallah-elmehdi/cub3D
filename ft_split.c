/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:15:22 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 09:46:05 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		str_table_length(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char *s, char c)
{
	char **output;
	int sep;
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	sep = str_table_length(s, c);
	output = (char **)ft_calloc(sizeof(char *), sep + 2);
	while (j <= sep)
	{
		a = 0;
		output[j] = (char*)ft_calloc(sizeof(char), 4);
		while (s[i] != 0 && s[i] != c)
			output[j][a++] = s[i++];
		j++;
	}
	return (output);
}
