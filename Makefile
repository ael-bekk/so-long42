# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 11:09:41 by ael-bekk          #+#    #+#              #
#    Updated: 2022/02/04 11:09:41 by ael-bekk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= main.c \
			inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c \
			inc/libft/ft_split.c inc/libft/ft_strlen.c inc/libft/ft_strnstr.c inc/libft/ft_putstr_fd.c \
			inc/libft/ft_itoa.c inc/libft/ft_calloc.c inc/libft/ft_bzero.c inc/libft/ft_strlcat.c inc/libft/ft_memset.c\
			valid_map_1.c valid_map_2.c free.c error_map.c \
			display.c init_struct.c init_paths.c moves.c init_list.c door_op_cl.c \
			header.c init_enemy.c init_from_beggin.c \
			init_imag.c attack.c frames.c frames_2.c move_enemy_1.c move_enemy_2.c move_enemy_3.c move_enemy_4.c hooks.c hooks_2.c mlx_functions.c win_game.c\
			
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