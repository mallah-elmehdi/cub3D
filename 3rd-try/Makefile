# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 19:42:32 by emallah           #+#    #+#              #
#    Updated: 2020/10/19 19:42:49 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: $(NAME)

FILES = ft_err.c get_next_line.c get_next_line_utils.c main.c 
	
$(NAME):
	@gcc -Wall -Wextra -Werror -L.. -lmlx -L/usr/include -lXext -lX11 -lm  $(FILES) cub3dEx
clean:
	@rm -f cub3dEx

re: clean all
