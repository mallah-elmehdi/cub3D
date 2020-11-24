// #include "../cub3d.h"

// int ft_collision_up(int x, int y)
// {
// 	int i;
// 	int j;

// 	j = 0;	
// 	x += -SZ_PLY / 2;
// 	y += -SZ_PLY / 2 - 1;
// 	while (j > -SPD)
// 	{
// 		i = 0;
// 		y = y + j;
// 		while (i < SZ_PLY)
// 		{
// 			if (g_mlx_str[x + i + y * g_img.res[0]] != CLR_0)
// 				return (j);
// 			i++;
// 		}
// 		j--;
// 	}
// 	return (j);
// }

// int ft_collision_down(int x, int y)
// {
// 	int i;
// 	int j;

// 	j = 0;	
// 	x += -SZ_PLY / 2;
// 	y += SZ_PLY / 2;
// 	while (j < SPD)
// 	{
// 		i = 0;
// 		y = y + j;
// 		while (i < SZ_PLY)
// 		{
// 			if (g_mlx_str[x + i + y * g_img.res[0]] != CLR_0)
// 				return (j);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (j);
// }

// int ft_collision_left(int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;	
// 	x += -SZ_PLY / 2;
// 	y += -SZ_PLY / 2;
// 	while (i > -SPD)
// 	{
// 		j = 0;
// 		x += i;
// 		while (j < SZ_PLY)
// 		{
// 			y = y + j;
// 			if (g_mlx_str[x + y * g_img.res[0]] != CLR_0)
// 				return (j);
// 			j++;
// 		}
// 		i--;
// 	}
// 	return (i);
// }
// int ft_collision_right(int x, int y)
// {
// 	int i;
// 	int j;

// 	i = 0;	
// 	x += SZ_PLY / 2;
// 	y += -SZ_PLY / 2;
// 	while (i < SPD)
// 	{
// 		j = 0;
// 		x += i;
// 		while (j < SZ_PLY)
// 		{
// 			y = y + j;
// 			if (g_mlx_str[x + y * g_img.res[0]] != CLR_0)
// 				return (j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i);
// }