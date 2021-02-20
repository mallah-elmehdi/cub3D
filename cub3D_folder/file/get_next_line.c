/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 07:20:55 by emallah           #+#    #+#             */
/*   Updated: 2020/10/21 19:12:51 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_next_line(int fd, char **line)
{
	int				a;
	int				j;
	static char		*one_for_all;

	j = 0;
	if (line == NULL)
		return (-1);
	if (!(*line = (char*)ft_calloc(sizeof(char), 1001)))
		return (-1);
	if ((a = (check_out(&one_for_all, line, &j)) > 0))
		return (1);
	if (a < 0)
		return (-1);
	if (one_for_all)
		free_it(&one_for_all);
	if (!(one_for_all = (char*)ft_calloc(sizeof(char), 1001)))
		return (-1);
	if ((a = fill_it(&one_for_all, line, &j, &fd)) > 0)
		return (1);
	if (a < 0)
		return (-1);
	free_it(&one_for_all);
	return (2);
}

char	*ft_calloc(int a, int b)
{
	int		i;
	long	c;
	char	*p;

	i = 0;
	c = a * b;
	p = (char *)malloc(c);
	if (!p)
		return (NULL);
	while (i < c)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
