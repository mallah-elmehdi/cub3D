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
	return (0);
}

void ft_draw_with_txt(int y, int x, int ln_h)
{
	int s_y;
	int s_x;
	// static int n;
	// static int w;
	// static int e;

	s_y = 0;
	s_x = g_ray.v ? g_ray.y % 32 : g_ray.x % 32;
	// printf("%d\n", g_ray.x);
	while (ln_h)
	{
		// if (g_ray.u && !g_ray.v)
		// 	g_mlx_str[x + ft_y(y)] = g_txt.g_so[s_y++];
		// if (g_ray.d && !g_ray.v)
		// 	g_mlx_str[x + ft_y(y)] = g_txt.g_no[s_y++];
		// if (g_ray.l && g_ray.d && g_ray.v)
		// 	g_mlx_str[x + ft_y(y)] = g_txt.g_we[s_y++];
		// if (g_ray.r && g_ray.d && g_ray.v)
		g_mlx_str[x + ft_y(y)] = g_txt.g_we[s_y * 32 + s_x];
		y++;
		s_y += ((float)32 / (float)ln_h);
		ln_h--;
	}
	if (s_y > 31) s_y = 0;
}