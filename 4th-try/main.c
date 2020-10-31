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

int main()
{

    // void    *mlx;
    int i = 0;
    int j = 0;
    struct the_infos infos;



    ft_initilisation(&infos, &map);
    	if (map[0])
    return (1);
    if (ft_read_file(&infos, map) == ERR)
        return (ERR);
    printf("F => %d-\n", infos.floor);
    printf("C => %d-\n", infos.ceilling);
    printf("R => %dx%d-\n", infos.resolution[0], infos.resolution[1]);
    printf("S => %s-\n", infos.s_texture);
    printf("SO => %s-\n", infos.so_texture);
    printf("WE => %s-\n", infos.we_texture);
    printf("EA => %s-\n", infos.ea_texture);
    printf("NO => %s-\n", infos.no_texture);

    while (i < ft_matrix_lenght(map))
    {
        while (j < ft_array_lenght(map[i]))
        {
            printf("%d", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    // mlx = mlx_init();
    // mlx_new_window(mlx, infos.resolution[0], infos.resolution[1], "salut");
    // mlx_loop(mlx);
}
