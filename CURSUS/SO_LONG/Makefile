# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 12:16:46 by druiz-ca          #+#    #+#              #
#    Updated: 2024/06/27 19:33:36 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = clang -g -Wall -Wextra -Werror
CFILES  = src/so_long.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line_utils2.c \
		src/move.c \
		src/mlx_functions.c \
		src/free_functions.c \
		src/so_long_utils.c \
		src/check_map.c \
		src/checks_map_main.c \
		src/checks_map_utils.c \

OFILES  = $(CFILES:.c=.o)
MLX42 = ./MLX42/libmlx42.a

$(NAME): $(OFILES)
	$(CC) $(CFILES) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean

re: fclean $(NAME)

.PHONY: all clean fclean re