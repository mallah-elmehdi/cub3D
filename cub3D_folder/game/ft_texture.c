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

void	ft_free_mem(void)
{
	while (g_fre_mem)
	{
		if (g_fre_mem == 1)
			free_it(&g_fre.m1);
		if (g_fre_mem == 2)
			free_it(&g_fre.m2);
		if (g_fre_mem == 3)
			free_it(&g_fre.m3);
		if (g_fre_mem == 4)
			free_it(&g_fre.m4);
		if (g_fre_mem == 5)
			free_it(&g_fre.m5);
		g_fre_mem--;
	}
}

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
	ft_free_mem();
	return (0);
}
