#include "../cub3d.h"

// void ft_draw_rect(int x, int y, int color)
// {
// 	int a;
// 	int b;
// 	int i;

// 	a = 0;
// 	while (a < SZ)
// 	{
// 		b = 0;
// 		while (b < SZ)
// 		{
// 			i = x * SZ + b + ft_y(y * SZ + a);
// 			g_mlx_str[i] = color;
// 			b++;
// 		}
// 		a++;
// 	}
// }

// void ft_draw_ply(void)
// {
// 	float a;
// 	float b;
// 	int x;
// 	int y;

// 	a = 0;
// 	while (a < 360)
// 	{
// 		b = 0;
// 		while (b < SZ_PY)
// 		{
// 			x = g_ply.x + b * ft_cos(a);
// 			y = g_ply.y + b * ft_sin(a);
// 			g_mlx_str[x + ft_y(y)] = C_PL;
// 			b++;
// 		}
// 		a++;
// 	}
// }

// void ft_draw_rays(void)
// {
// 	float a;
// 	float b;
// 	int x;
// 	int y;
// 	int stop;

// 	a = -AGL;
// 	while (a <= AGL)
// 	{
// 		b = 0;
// 		stop = ft_hit(a);
// 		while (b <= stop)
// 		{
// 			x = g_ply.x + b * ft_cos(a + g_ply.trn);
// 			y = g_ply.y + b * ft_sin(a + g_ply.trn);
// 				g_mlx_str[x + ft_y(y)] = C_PL;
// 			b++;
// 		}
		
// 		a += 0.3;
// 	}
// }

// void ft_draw_map(void)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (g_map[i] != NULL)
// 	{
// 		j = 0;
// 		while (g_map[i][j] != 0)
// 		{
// 			if (g_map[i][j] == '1')
// 				ft_draw_rect(j, i, C_1);
// 			else if (g_map[i][j] == '2')
// 				ft_draw_rect(j, i, C_2);
// 			else if (g_map[i][j] == '0' || ft_is_player(g_map[i][j]))
// 				ft_draw_rect(j, i, C_0);
// 			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
// 				ft_ply_init_ok(i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void ft_rays(void)
{
	float a;
	float ray;
	float ln_height;
	int x;
	int y;

	a = -AGL;
	x = 0;
	while (a <= AGL)
	{
		ray = ft_hit(a) * ft_cos(a);
		ln_height = (SZ / ray) * ((float)g_img.rsl[0] / 2 / ft_tan(AGL));
		y = ((float)g_img.rsl[1] - 1) / 2 - (ln_height / 2);
		y = y < 0 ? 0 : y;
		ft_draw_with_txt(y, x, ln_height);
		// if (g_spt)
		// 	ft_spt(x, a);
		x++;
		a += g_ray.agl;
	}
	if (g_bmp)
		ft_draw_bmp();
}

void ft_draw_cel_flr()
{
	long i;

	i = 0;
	while (i < g_img.rsl[0] + ft_y((g_img.rsl[1] - 1) / 2))
		g_mlx_str[i++] = g_info.cel;
	while (i < g_img.rsl[0] + ft_y(g_img.rsl[1] - 1))
		g_mlx_str[i++] = g_info.flr;
}


void ft_ply_init(void)
{
	int i;
	int j;

	i = 0;
	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (ft_is_player(g_map[i][j]) && !g_ply.x && !g_ply.y)
			{
				g_ply.x = j * SZ + SZ / 2;
				g_ply.y = i * SZ + SZ / 2;
				if (g_map[i][j] == 'N')
					g_ply.trn = -90;
				if (g_map[i][j] == 'E')
					g_ply.trn = 180;
				if (g_map[i][j] == 'S')
					g_ply.trn = 90;
				if (g_map[i][j] == 'W')
					g_ply.trn = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}

void ft_init_map_draw(void)
{
	ft_draw_cel_flr();
	ft_ply_init();
	ft_rays();
}