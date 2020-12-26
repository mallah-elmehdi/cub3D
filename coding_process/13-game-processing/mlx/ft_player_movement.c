#include "../cub3d.h"

void ft_move_up(void)
{
    int a;
    
    a = 0;
    if (g_mlx_str[g_ply.x + (g_ply.y - SIZE_PLY) * g_img.res[0]] == 0xFFFFFF 
    && g_mlx_str[g_ply.x + SIZE_PLY - 1 + (g_ply.y - SIZE_PLY) * g_img.res[0]] == 0xFFFFFF)
        a = SIZE_PLY;
    else
    {
        while (g_mlx_str[g_ply.x + (g_ply.y - a - 1) * g_img.res[0]] == 0xFFFFFF
        && g_mlx_str[g_ply.x + SIZE_PLY - 1 + (g_ply.y - a - 1) * g_img.res[0]] == 0xFFFFFF)
            a++;
    }
	g_ply.y -= a;
}

void ft_move_down(void)
{
    int a;
    
    a = 0;
    if (g_mlx_str[g_ply.x + (g_ply.y + SIZE_PLY * 2) * g_img.res[0]] == 0xFFFFFF
    && g_mlx_str[g_ply.x + SIZE_PLY - 1 + (g_ply.y + SIZE_PLY * 2) * g_img.res[0]] == 0xFFFFFF)
        a = SIZE_PLY;
    else
    {
        while (g_mlx_str[g_ply.x + (g_ply.y + SIZE_PLY + a) * g_img.res[0]] == 0xFFFFFF
        && g_mlx_str[g_ply.x + SIZE_PLY - 1 + (g_ply.y + SIZE_PLY + a) * g_img.res[0]] == 0xFFFFFF)

            a++;
    }
    g_ply.y += a;
}

void ft_move_right(void)
{
    int a;
    
    a = 0;
    if (g_mlx_str[g_ply.x + SIZE_PLY * 2 + g_ply.y * g_img.res[0]] == 0xFFFFFF
    && g_mlx_str[g_ply.x + SIZE_PLY * 2 + (g_ply.y + SIZE_PLY - 1) * g_img.res[0]] == 0xFFFFFF)
        a = SIZE_PLY;
    else
    {
        while (g_mlx_str[g_ply.x + SIZE_PLY + a + g_ply.y * g_img.res[0]] == 0xFFFFFF
        && g_mlx_str[g_ply.x + SIZE_PLY + a + (g_ply.y + SIZE_PLY - 1) * g_img.res[0]] == 0xFFFFFF)
        
            a++;
    }
    g_ply.x += a;

}

void ft_move_left(void)
{
    int a;
    
    a = 0;
    if (g_mlx_str[g_ply.x - SIZE_PLY + g_ply.y * g_img.res[0]] == 0xFFFFFF
    && g_mlx_str[g_ply.x - SIZE_PLY + (g_ply.y + SIZE_PLY -1) * g_img.res[0]] == 0xFFFFFF)
        a = SIZE_PLY;
    else
    {
        while (g_mlx_str[g_ply.x - a - 1 + g_ply.y * g_img.res[0]] == 0xFFFFFF
        && g_mlx_str[g_ply.x - a - 1 + (g_ply.y + SIZE_PLY -1) * g_img.res[0]] == 0xFFFFFF)
            a++;
    }
    g_ply.x -= a;
}