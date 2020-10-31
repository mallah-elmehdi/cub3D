#include "cub3d.h"

int     ft_read_file(struct the_infos *fill_infos, int **map)
{
    int		fd;
	char	*line;
	
	if ((fd = open("map.cub", O_RDONLY)) == ERR)
		return ft_err("ERROR: file error");
	while (get_next_line(fd, &line) == 1) 
	{
		if (ft_info_reader(line, fill_infos) == ERR)
			return (ERR);
		if (ft_map_reader(line, map) == ERR)
			return (ERR);
		// free_it(&line);
	}
	return (1);
}