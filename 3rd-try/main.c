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

int main() {

    void    *mlx;
    struct  the_infos infos;
    
    if (ft_read_file(&infos) == ERR)
        return (ERR);
    mlx = mlx_init();
    mlx_new_window(mlx, infos.resolution[0], infos.resolution[1], "Hello world!");
    mlx_loop(mlx);
} 
