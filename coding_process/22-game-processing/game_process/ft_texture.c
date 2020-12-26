#include "../cub3d.h"

int ft_game_texture()
{
	void *hold;
	int sz;
	
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

void ft_draw_with_txt(int y, int x, int ln_h)
{
	int s_y;
	int s_x;
	int sz;
	int btm_idx;
	
	sz = SZ;
	btm_idx = ln_h > g_info.rsl[1] ?  g_info.rsl[1] : ln_h;
	s_x = g_ray.v ? g_ray.y % SZ : g_ray.x % SZ;
	while (btm_idx)
	{
		s_y = (y + ln_h / 2 - g_info.rsl[1] / 2) * ((float)sz / (float)ln_h);
		if (g_ray.u && !g_ray.v)
			g_mlx_str[x + ft_y(y)] = g_txt.g_no[s_y * SZ + s_x];
		else if (g_ray.d && !g_ray.v)
			g_mlx_str[x + ft_y(y)] = g_txt.g_so[s_y * SZ + s_x];
		else if (g_ray.v && g_ray.l)
			g_mlx_str[x + ft_y(y)] = g_txt.g_we[s_y * SZ + s_x];
		else if (g_ray.v && g_ray.r)
			g_mlx_str[x + ft_y(y)] = g_txt.g_ea[s_y * SZ + s_x];
		y++;
		btm_idx--;
	}
}

void ft_draw_bmp(void)
{
	int i;
	int y;
	int x;

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

void ft_spt (int x, float a)
{
	float ln_h = 0;
	int btm_idx;
	int y;
	int s_x;
	int s_y;

	if (a) a += 0;
	// g_spt_ray *= ft_cos(a);
	// ln_h = (SZ /  g_spt_ray) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
	btm_idx = ln_h > g_info.rsl[1] ?  g_info.rsl[1] : ln_h;
	y = ((float)g_img.rsl[1] - 1) / 2 - (ln_h / 2);
	y = y < 0 ? 0 : y;
	s_x = g_ray.x % SZ;
	while (btm_idx)
	{
		s_y = (y + ln_h / 2 - g_info.rsl[1] / 2) * (32.00/ (float)ln_h);
		g_mlx_str[x + ft_y(y)] = g_txt.g_s[s_y * SZ + s_x];
		y++;
		btm_idx--;
	}
}