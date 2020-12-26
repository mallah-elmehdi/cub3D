#include "cub3d.h"

int ft_read_info(struct the_infos *fill_infos)
{
	int fd;
	char *line;

	if ((fd = open(file_name, O_RDONLY)) == ERR)
		return ft_err("ERROR: file error");
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_info_reader(line, fill_infos) == ERR)
			return (ERR);
		if (!ft_is_info_done(fill_infos))
			g_map_start++;
		
	}
	return (1);
}

int ft_read_map()
{
	int fd;
	int start;
	char *line;

	start = 0;
	if ((fd = open(file_name, O_RDONLY)) == ERR)
		return ft_err("ERROR: file error");
	while (get_next_line(fd, &line) == 1)
	{
		if (start == g_map_start)
		{
			if (ft_map_reader(line) == ERR)
				return (ERR);
		}
		else
			start++;
	}
	return (1);
}

int ft_read_file(struct the_infos *fill_infos)
{
	if (ft_read_info(fill_infos) == ERR)
		return (ERR);
	if (ft_height_width_map() == ERR)
		return (ERR);
	map = (char **)malloc(sizeof(char *) * (g_map_height + 1));
	map[g_map_height] = NULL;
	if (ft_read_map() == ERR)
		return (ERR);
	return (1);
}