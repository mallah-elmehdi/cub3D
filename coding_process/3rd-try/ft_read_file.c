#include "cub3d.h"

int     ft_read_file(struct the_infos *fill_infos)
{
    int		fd;
	char	*line;
	
	if ((fd = open("the_map.cub", O_RDONLY)) == ERR)
		return ft_err("ERROR: file error");
	while (get_next_line(fd, &line) == 1) 
	{
		if (ft_info_reader(line, fill_infos) == ERR)
			return (ERR);
		if (ft_map_reader(line) == ERR)
			return (ERR);
		free_it(&line);
	}
	return (1);
}