/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:26:23 by emallah           #+#    #+#             */
/*   Updated: 2020/12/10 12:26:25 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bmp_header(void)
{
	g_bmp_header.sgn = "BM";
	g_bmp_header.size = (g_info.rsl[0] * g_info.rsl[1] * 4) + 54;
	g_bmp_header.zr = 0;
	g_bmp_header.oft = 54;
	g_bmp_header.bmh = 40;
	g_bmp_header.pii = 1;
	g_bmp_header.bpp = 32;
}

int		ft_bmp_init(void)
{
	if ((g_bmp_fd = open("image.bmp", O_RDWR | O_TRUNC | O_CREAT, 0600)) == ERR)
		return (ft_err("ERROR\nBM file error: somthing went wrong"));
	ft_bmp_header();
	write(g_bmp_fd, g_bmp_header.sgn, 2 * sizeof(char));
	write(g_bmp_fd, &g_bmp_header.size, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.oft, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.bmh, sizeof(int));
	write(g_bmp_fd, &g_info.rsl[0], sizeof(int));
	write(g_bmp_fd, &g_info.rsl[1], sizeof(int));
	write(g_bmp_fd, &g_bmp_header.pii, 2);
	write(g_bmp_fd, &g_bmp_header.bpp, 2);
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	write(g_bmp_fd, &g_bmp_header.zr, sizeof(int));
	return (0);
}

void	ft_draw_bmp(void)
{
	int		i;
	int		y;
	int		x;

	y = g_info.rsl[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < g_info.rsl[0])
		{
			i = g_mlx_str[x + ft_y(y)];
			write(g_bmp_fd, &i, sizeof(int));
			x++;
		}
		y--;
	}
	mlx_destroy_image(g_mlx, g_mlx_img);
}
