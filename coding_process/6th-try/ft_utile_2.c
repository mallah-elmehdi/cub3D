
#include "cub3d.h"

int ft_is_player(char c)
{
	if (c == 'W' || c == 'S' || c == 'E' || c == 'N')
		return (1);
	return (0);
}

int ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int ft_is_map(char c)
{
	if (c == '0' || c == '1' || c == '2')
		return (1);
	return (0);
}

int ft_height_width_map()
{
	int fd;
	int i;
	char *line;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == ERR)
		return ft_err("ERROR: file error");
	while (get_next_line(fd, &line) == 1)
	{
		ft_strtrim_one_side(&line);
		while (line[i] != 0 && ft_is_whitespace(line[i]))
			i++;
		if (line[i] == 0 || ft_is_map(line[i]))
			g_map_height++;
		if (g_map_width < (int)ft_strlen(line))
			g_map_width = ft_strlen(line);
	}
	return (1);
}