/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:28:06 by emallah           #+#    #+#             */
/*   Updated: 2020/10/22 14:09:45 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
size_t	ft_strlen(char *str);
int		index_front(char *str);
int		index_back(char *str);
void	ft_strtrim(char **line);
char	**ft_split(char *s, char c);
int		str_table_length(char *s, char c);
int		ft_atoi(char *s);

// --- ERR
int		ft_err(char *str);

// ---- MAP
int		ft_resolution(char *line);
int		ft_check_synx(char *line);
int		ft_texture(char *line);
int		ft_sprite_texture(char *line);
int		the_color(char *file);
int		ft_color(char *line);
int     ft_map_reader(void);
int		ft_is_map(char *line);

#endif
