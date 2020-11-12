#include "../cub3d.h"

void ft_move_up(void)
{
    int a;

    a = ft_collision_up(g_ply.x, g_ply.y);
    g_ply.y += a;
}

void ft_move_down(void)
{

    int a;

    a = ft_collision_down(g_ply.x, g_ply.y);
    g_ply.y += a;
}

void ft_move_left(void)
{
    int a;

    a = ft_collision_left(g_ply.x, g_ply.y);
    g_ply.x += a;
}

void ft_move_right(void)
{
    int a;

    a = ft_collision_right(g_ply.x, g_ply.y);
    g_ply.x += a;
}