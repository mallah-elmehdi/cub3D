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

struct the_infos {
    int resolution[2];
    char *so_texture;
    char *we_texture;
    char *no_texture;
    char *ea_texture;
    char *s_texture;
    int floor;
    int c;
};

// ---- GET NEXT LINE 
void	*ft_calloc(size_t type, size_t size);
int		check_out(char **str1, char **str2, int *i);
int		fill_it(char **string1, char **string2, int *h, int *s);
int		re_alloc(char **str);
int		len(char *s);
int		after_check(char **str1, char **str2, int *i);
void	free_it(char **s);
int		get_next_line(int fd, char **line);

// ---- LIBFT
// size_t	ft_strlen(char *str);
// int		index_front(char *str);
// int		index_back(char *str);
// void	ft_strtrim(char **line);
// char	**ft_split(char *s, char c);
// int		str_table_length(char *s, char c);
// int		ft_atoi(char *s);
// int		ft_strlen_trim(char *str);
//void	ft_strtrim_one_side(char **line);

// --- ERR
// int		ft_err(char *str);

// ---- MAP
// int		ft_skip_space(char *line);
// int		ft_info_reader(char *line);
// int		ft_get_dimension(char line, int *i);
// int		ft_resolution(char *line);
// int		ft_color(char *line);
// int		the_color(char **line);
// int		ft_is_texture(char **line);
// int		ft_texture(char *line);
// int		string_length(char *s, char c);

#endif
