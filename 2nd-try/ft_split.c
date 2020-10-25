/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:15:22 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 20:34:04 by emallah          ###   ########.fr       */
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

int		string_length(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
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
	output = (char **)malloc(sizeof(char *) * (sep + 2));
	output[sep + 1] = NULL;
	while (j <= sep)
	{
		a = 0;
		i = string_length(s, c);
		output[j] = (char*)ft_calloc(sizeof(char), i + 1);
		while (*s != 0 && *s != c)
			output[j][a++] = *s++;
		j++;
	}
	return (output);
}
