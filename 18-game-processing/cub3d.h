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
# define SZ 22
# define SZ_PY 10
# define W_S SZ_PY
# define T_S 10

# define PI 3.14159265358979323846

# define RT_ROT 124
# define LT_ROT 123
# define UP 13
# define DN 1
# define LT 0
# define RT 2
# define ESC 53

# define C_0 16777215
# define C_1 7127551
# define C_2 15103231
# define C_PL 15990784

// # define RIGHT_ROT 65363
// # define LEFT_ROT 65361
// # define UP 119
// # define DOWN 115
// # define LEFT 97
// # define RIGHT 100
// # define ESC 65307

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_info
{
	char		*so_txt;
	char		*we_txt;
	char		*no_txt;
	char		*ea_txt;
	char		*s_txt;
	int			rsl[2];
	int			flr;
	int			cel;
}				t_info;

typedef struct	s_img
{
	int			rsl[2];
	int			bpp;
	int			sz_ln;
	int			e;
}				t_img;

typedef struct	s_ply
{
    float		x;
    float		y;
    float		wlk;
    float		trn;
}				t_ply;

typedef struct	s_ray
{
    int			r;
    int			l;
    int			u;
    int			d;
}				t_ray;

typedef struct	s_hv
{
    int			x;
    int			y;
}				t_hv;

void			*g_mlx;
void			*g_mlx_win;
void            *g_mlx_img;
int             *g_mlx_str;

void			*g_param;
char			**g_map;
char			*g_file_name;
int				g_map_start;
int				g_map_height;
int				g_map_width;
int				g_gnl;
int				g_ystp;
int				g_xstp; 

struct s_img	g_img;
struct s_info	g_info;
struct s_ply	g_ply;
struct s_ray	g_ray;
struct s_hv		g_h;
struct s_hv		g_v;

void			*ft_calloc(size_t type, size_t size);
void			free_it(char **s);
void			free_it_double(char **s, int counter);
void			ft_strtrim(char **line);
void			ft_strtrim_one_side(char **line);
void			ft_dimension(char *line, int *x, int *y);
void			ft_initilisation(char *file);
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
int				ft_read_file(void);
int				ft_resolution_syntax(char *line);
int				ft_resolution_errors(char *line);
int				ft_resolution_add(char *line);
int				ft_resolution(char *line);
int				ft_info_reader(char *line);
int				ft_color_syntax(char *line);
int				ft_color_errors(char **rgb);
int				ft_color(char *line, char c);
int				ft_is_int(char c);
int				ft_texture(char *line);
int				ft_texture_str(char *line, char **texture, int start);
int				ft_texture_add(char *line, char *txt);
int				ft_is_info_done(void);
int				ft_is_player(char c);
int				ft_map_reader(char *line);
int				ft_read_map();
int				ft_read_info(void);
int				ft_is_whitespace(char c);
int				ft_is_map(char c);
int				ft_height_width_map();
int				ft_map_errors();
int				ft_is_map_has_empty_line();
int				ft_map_check_1(int i, int j);
int				ft_map_check_2(int i, int j);
int				ft_map_check_3(int i, int j);
int				ft_check_map(void);
// =====================================
void			ft_game(void);
void			ft_game_loop(void);
void			ft_game_var_init(void);
void			ft_draw_map(void);
void			ft_draw_rect(int x, int y, int color);
void			ft_ply_init(int i, int j);
void			ft_quit(void);
int				ft_allowed_key(int key);
// --------------------------------------
void			ft_update_img(int key_code);
float			ft_cos(float o);
float			ft_sin(float o);
float			ft_tan(float o);
void			ft_draw_ply(void);
void			ft_draw_rays(void);
void ft_ray_dir(float agl);
int ft_hit(float o);
int ft_v_hit(float o);
int ft_h_hit(float o);
int ft_is_wall(int x, int y);
int ft_y(float i);
void ft_hit_init_v(int *x, int *y, int *add, int o);
void ft_hit_init_h(int *x, int *y, int *add, int o);

#endif
