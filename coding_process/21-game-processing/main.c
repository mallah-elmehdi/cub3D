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

int main(int ac, char **av)
{
	if (ac == 10)
		return (0);
	ft_initilisation(av[1]);
	if (ft_read_file())
		return (ERR);
	if (ft_map_errors())
		return (ERR);
	if (ft_game())
		return (ERR);
	mlx_loop(g_mlx);
	return (0);
}
