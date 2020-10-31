/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:27:35 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 11:57:17 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_get_dimension(char line, int *i)
{
    int dim;

    dim = 0;
    while (line[*i] != 0 && line[*i] >= 48 && line[*i] <= 57 && dim <= 5121)
    {
        dim = (dim * 10) + (line[*i] - 48);
        *i = *i + 1;
    }
    return (dim);
}

int ft_resolution_syntax(char *line)
{
    int i;

    i = 1;
    if (line[2] != ' ')
        return (ft_err("ERROR RESOLUTION: syntax error"));
    while (line[i] != 0)
    {
        if (!(line[i] >= 48 && line[i] <= 57))
            return (ft_err("ERROR RESOLUTION: syntax error"));
        i++;
    }
    return (1);
}

int ft_resolution_errors(char *line)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while (line[i] != 0)
    {
        if (line[i] >= 48 && line[i] <= 57)
        {
            a++;
            while (line[i] >= 48 && line[i] <= 57)
                i++;
        }
        i++;
    }
    if (a != 2)
        return (ft_err("ERROR RESOLUTION: arguments error"));
    return (1);
}

int ft_resolution(char *line, struct the_infos *fill_infos)
{
    int i;

    i = 0;
    ft_strtrim(&line);
    if (ft_resolution_check(line) == ERR)
        return (ERR);
    if (ft_resolution_errors(line) == ERR)
        return (ERR);
    while (line[i] != 0)
    {
        if (line[i] >= 48 && line[i] <= 57 && x == -1)
            x = ft_get_dimension(line, &i);
        else if (line[i] >= 48 && line[i] <= 57 && y == -1)
            y = ft_get_dimension(line, &i);
        else if (line[i] >= 48 && line[i] <= 57 && y > -1 && x > -1)
            return (ft_err("ERROR RESOLUTION: syntax error"))
                i++;
    }
    if (x > 5120 || y > 2880)
        return (ft_err("ERROR RESOLUTION: you exceed the built in Retina display (5120 x 2880)"));
    if (x == -1 || y == -1)
        return (ft_err("ERROR RESOLUTION: missing required information (x or y)"));
    return (1);
}
