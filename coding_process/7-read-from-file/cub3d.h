/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:28:06 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 20:26:53 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ERR -1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_the_infos
{
	char		*so_texture;
	char		*we_texture;
	char		*no_texture;
	char		*ea_texture;
	char		*s_texture;
	int			resolution[2];
	int			floor;
	int			ceilling;
}				t_the_infos;

char			**g_map;
char			*g_file_name;
int				g_map_start;
int				g_map_height;
int				g_map_width;
int				g_gnl;

void			*ft_calloc(size_t type, size_t size);
void			free_it(char **s);
void			free_it_double(char **s, int counter);
void			ft_strtrim(char **line);
void			ft_strtrim_one_side(char **line);
void			ft_dimension(char *line, int *x, int *y);
void			ft_initilisation(struct s_the_infos *info, char *file);
void			free_it_double_int(int **s, int counter);
char			**ft_split(char *s, char c);
size_t			ft_strlen(char *str);
int				check_out(char **str1, char **str2, int *i);
int				fill_it(char **string1, char **string2, int *h, int *s);
int				re_alloc(char **str);
int				len(char *s);
int				after_check(char **str1, char **str2, int *i);
int				get_next_line(int fd, char **line);
int				index_front(char *str);
int				index_back(char *str);
int				str_table_length(char *s, char c);
int				string_length(char *s, char c);
int				ft_atoi(char *s);
int				ft_strlen_trim(char *str);
int				ft_err(char *str);
int				ft_read_file(struct s_the_infos *fill_infos);
int				ft_resolution_syntax(char *line);
int				ft_resolution_errors(char *line);
int				ft_resolution_add(char *line, struct s_the_infos *fill_infos);
int				ft_resolution(char *line, struct s_the_infos *fill_infos);
int				ft_info_reader(char *line, struct s_the_infos *fill_infos);
int				ft_color_syntax(char *line);
int				ft_color_errors(char **rgb);
int				ft_color(char *line, struct s_the_infos *fill_infos, char c);
int				ft_is_int(char c);
int				ft_texture(char *line, struct s_the_infos *fill_infos);
int				ft_texture_str(char *line, char **texture, int start);
int				ft_texture_add(char *line, struct s_the_infos *info, char *txt);
int				ft_is_info_done(struct s_the_infos *info);
int				ft_is_player(char c);
int				ft_map_reader(char *line);
int				ft_read_map();
int				ft_read_info(struct s_the_infos *fill_infos);
int				ft_is_whitespace(char c);
int				ft_is_map(char c);
int				ft_height_width_map();
int				ft_map_errors();
int				ft_is_map_has_empty_line();
int				ft_map_check_1(int i, int j);
int				ft_map_check_2(int i, int j);
int				ft_map_check_3(int i, int j);

#endif
