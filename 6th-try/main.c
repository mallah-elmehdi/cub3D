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

    // void    *mlx;
    int i = 0;
    if (ac == 10)
        return (0);
    struct the_infos infos;
    ft_initilisation(&infos, av[1]);
    if (ft_read_file(&infos) == ERR)
        return (ERR);
    if (ft_map_errors() == ERR)
        return (ERR);
    
    // printf("F => %d-\n", infos.floor);
    // printf("C => %d-\n", infos.ceilling);
    // printf("R => %dx%d-\n", infos.resolution[0], infos.resolution[1]);
    // printf("S => %s-\n", infos.s_texture);
    // printf("SO => %s-\n", infos.so_texture);
    // printf("WE => %s-\n", infos.we_texture);
    // printf("EA => %s-\n", infos.ea_texture);
    // printf("NO => %s-\n", infos.no_texture);
    while (map[i] != NULL)
    {
        printf("-->%s<--\n", map[i]);
        i++;
    }
    // mlx = mlx_init();
    // mlx_new_window(mlx, infos.resolution[0], infos.resolution[1], "salut");
    // mlx_loop(mlx);
}
