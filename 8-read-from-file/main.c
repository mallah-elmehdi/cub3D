/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:30:40 by emallah           #+#    #+#             */
/*   Updated: 2020/10/25 10:27:35 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	void				*mlx;
	struct s_the_infos	infos;

	if (ac == 10)
		return (0);
	ft_initilisation(&infos, av[1]);
	if (ft_read_file(&infos))
		return (ERR);
	if (ft_map_errors())
		return (ERR);
	mlx = mlx_init();
	mlx_new_window(mlx, infos.resolution[0], infos.resolution[1], "salut");
	mlx_loop(mlx);
	return (0);
}
