/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:01 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:38:02 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_game_texture(void)
{
	void	*hold;
	int		sz;

	sz = SZ;
	if (!(hold = mlx_xpm_file_to_image(g_mlx, g_info.no_txt, &sz, &sz)))
		return (ft_err("ERROR\nno texture error : file not found!"));
	g_txt.g_no = (int *)mlx_get_data_addr(hold, &g_img.bpp, &sz, &g_img.e);
	if (!(hold = mlx_xpm_file_to_image(g_mlx, g_info.so_txt, &sz, &sz)))
		return (ft_err("ERROR\nso texture error : file not found!"));
	g_txt.g_so = (int *)mlx_get_data_addr(hold, &g_img.bpp, &sz, &g_img.e);
	if (!(hold = mlx_xpm_file_to_image(g_mlx, g_info.we_txt, &sz, &sz)))
		return (ft_err("ERROR\nwe texture error : file not found!"));
	g_txt.g_we = (int *)mlx_get_data_addr(hold, &g_img.bpp, &sz, &g_img.e);
	if (!(hold = mlx_xpm_file_to_image(g_mlx, g_info.ea_txt, &sz, &sz)))
		return (ft_err("ERROR\nea texture error : file not found!"));
	g_txt.g_ea = (int *)mlx_get_data_addr(hold, &g_img.bpp, &sz, &g_img.e);
	if (!(hold = mlx_xpm_file_to_image(g_mlx, g_info.s_txt, &sz, &sz)))
		return (ft_err("ERROR\ns texture error : file not found!"));
	g_txt.g_s = (int *)mlx_get_data_addr(hold, &g_img.bpp, &sz, &g_img.e);
	return (0);
}
