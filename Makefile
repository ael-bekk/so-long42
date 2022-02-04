# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 11:09:41 by ael-bekk          #+#    #+#              #
#    Updated: 2022/02/04 17:52:10 by ael-bekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= files/main.c \
			inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c \
			inc/libft/ft_split.c inc/libft/ft_strlen.c inc/libft/ft_strnstr.c inc/libft/ft_putstr_fd.c \
			inc/libft/ft_itoa.c inc/libft/ft_calloc.c inc/libft/ft_bzero.c inc/libft/ft_strlcat.c inc/libft/ft_memset.c\
			files/valid_map_1.c files/valid_map_2.c files/free.c files/error_map.c \
			files/display.c files/init_struct.c files/init_paths.c files/moves.c files/init_list.c files/door_op_cl.c \
			files/header.c files/init_enemy.c files/init_from_beggin.c \
			files/init_imag.c files/attack.c files/frames.c files/frames_2.c \
			files/move_enemy_1.c files/move_enemy_2.c files/move_enemy_3.c files/move_enemy_4.c files/hooks.c files/hooks_2.c \
			files/mlx_functions.c files/win_game.c
			
FLGS	= gcc -Wextra -Wall -Werror

RM		= rm -f

all:	$(NAME) $(SRCS)

$(NAME):  	$(SRCS)
			@$(FLGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)
			@echo "\033[0;32mso_long is ready"

clean:
			@$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re