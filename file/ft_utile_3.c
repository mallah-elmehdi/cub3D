/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:57:10 by emallah           #+#    #+#             */
/*   Updated: 2020/11/03 18:57:14 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_stridt(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i != 6)
		return (1);
	if (str[0] != '-' || str[1] != '-' || str[2] != 's'
		|| str[3] != 'a' || str[4] != 'v' || str[5] != 'e')
		return (1);
	return (0);
}

void	ft_fill_map(char **map, char *line)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		map[0][i] = line[i];
		i++;
	}
}

int		ft_check_input(int ac, char **av)
{
	int		i;

	if (ac > 3 || ac < 2)
		return (ft_err("ERROR\nwrong number of arguments."));
	i = ft_strlen(av[1]);
	if (i < 5 || av[1][i - 1] != 'b'
		|| av[1][i - 2] != 'u' || av[1][i - 3] != 'c'
		|| av[1][i - 4] != '.' || av[1][i - 5] == '/')
		return (ft_err("ERROR\nfile error: invalid file name"));
	if (ac == 3)
	{
		g_bmp = 1;
		if (ft_stridt(av[2]))
			return (ft_err("ERROR\ninvalid input"));
	}
	return (0);
}

int		ft_height_width_map(void)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	j = 0;
	fd = open(g_file_name, O_RDONLY);
	while ((g_gnl = get_next_line(fd, &line)))
	{
		ft_strtrim_one_side(&line);
		i = 0;
		if ((j++) >= g_map_start)
		{
			while (line[i] != 0 && ft_is_whitespace(line[i]))
				i++;
			if (line[i] == 0 || ft_is_map(line[i]))
				g_map_height++;
			if (g_map_width < (int)ft_strlen(line))
				g_map_width = ft_strlen(line);
		}
		free_it(&line);
		if (g_gnl == 2)
			break ;
	}
	return (0);
}
