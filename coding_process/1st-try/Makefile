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

NAME = cub3d.a

all: $(NAME)
	
$(NAME):
	@gcc -Wall -Wextra -Werror -c ft_err.c get_next_line.c get_next_line_utils.c main.c
	@ar -rc $(NAME) *.o 
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
