# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 12:16:23 by daniel            #+#    #+#              #
#    Updated: 2025/04/04 12:46:08 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= iter
SRC= main.cpp
CC= c++
FLAGS= -std=c++98 -Wall -Wextra -Werror
RM= rm -f
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re
