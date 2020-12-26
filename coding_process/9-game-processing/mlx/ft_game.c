#include "../cub3d.h"

void ft_game(struct s_the_infos *infos)
{
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	struct s_img img;
	void *mlx;
	void *mlx_win;
	void *mlx_img;
	int *mlx_str;

	mlx = mlx_init();
	mlx_img = mlx_new_image(mlx, infos->resolution[0], infos->resolution[1]);
	mlx_win = mlx_new_window(mlx, infos->resolution[0], infos->resolution[1], "salut");
	ft_game_init(&img, infos);
	mlx_str = (int *)mlx_get_data_addr(mlx_img, &img.bpp, &img.size_line, &img.endian);

	while (g_map[i] != NULL)
	{
		j = 0;
		while (g_map[i][j] != 0)
		{
			if (g_map[i][j] == '1')
			{
				a = 0;
				while (a < 30)
				{
					b = 0;
					while (b < 30)
					{
						mlx_str[(j * 30) + b + (((i * 30) + a) * infos->resolution[0])] = 0xFF5733;
						b++;
					}
					a++;
				}
			}
			else if (g_map[i][j] == '0')
			{
				a = 0;
				while (a < 30)
				{
					b = 0;
					while (b < 30)
					{
						mlx_str[(j * 30) + b + (((i * 30) + a) * infos->resolution[0])] = 0xFFFFFF;
						b++;
					}
					a++;
				}
			}
			else if(ft_is_player(g_map[i][j]))
			{
				a = 0;
				while (a < 30)
				{
					b = 0;
					while (b < 30)
					{
						mlx_str[(j * 30) + b + (((i * 30) + a) * infos->resolution[0])] = 0x0030FF;
						b++;
					}
					a++;
				}
			}
			else
			{
				a = 0;
				while (a < 30)
				{
					b = 0;
					while (b < 30)
					{
						mlx_str[(j * 30) + b + (((i * 30) + a) * infos->resolution[0])] = 0x000000;
						b++;
					}
					a++;
				}
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, mlx_img, 0, 0);
	mlx_loop(mlx);
}