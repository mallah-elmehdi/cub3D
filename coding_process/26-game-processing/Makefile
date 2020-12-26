# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 19:42:32 by emallah           #+#    #+#              #
#    Updated: 2020/12/10 14:38:13 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILE = ./file/ft_atoi.c ./file/ft_check_map.c ./file/ft_color.c ./file/ft_err.c ./file/ft_info_reader.c\
	   ./file/ft_map_reader.c ./file/ft_read_file.c ./file/ft_resolution.c ./file/ft_split.c\
	   ./file/ft_strlen.c ./file/ft_strtrim.c ./file/ft_strtrim_one_side.c ./file/ft_texture.c\
	   ./file/ft_utile.c ./file/ft_utile_2.c ./file/ft_utile_3.c ./file/get_next_line.c ./file/get_next_line_utils.c

MAIN = main.c

GAME = ./game/ft_bitmap.c ./game/ft_collision.c ./game/ft_draw.c ./game/ft_game.c ./game/ft_movement.c\
	   ./game/ft_sprite.c ./game/ft_texture.c ./game/ft_utile_0.c ./game/ft_utile_1.c ./game/ft_utile_2.c

all: 
	@gcc -g -Werror -Wall -Wextra $(FILE) $(GAME) $(MAIN) -lmlx -framework OpenGL -framework AppKit

clean:
	rm cub3D

re: clean all
