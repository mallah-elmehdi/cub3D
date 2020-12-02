#include "../cub3d.h"

int   ft_allowed_key(int key)
{
    if (key == UP || key == DN || key == RT
	|| key == LT || key == LT_ROT || key == RT_ROT)
        return (1);
    return (0);
}

float ft_cos(float o)
{
	return (cos(o * PI / 180));
}

float ft_sin(float o)
{
	return (sin(o * PI / 180));
}

float ft_tan(float o)
{
	return (tan(o * PI / 180));
}

int ft_y(float i)
{
	return (i * g_img.rsl[0]);
}