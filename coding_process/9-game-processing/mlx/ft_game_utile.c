#include "../cub3d.h"

void	ft_game_init(struct s_img *img, struct s_the_infos *infos)
{
	img->bpp = 32;
	img->size_line = infos->resolution[0];
}