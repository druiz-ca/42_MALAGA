# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 13:20:11 by daniel            #+#    #+#              #
#    Updated: 2025/04/03 18:08:56 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= whatever
SRC= main.cpp
CC= c++
FLAGS= -std=c++98 -Wall -Werror -Wextra
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

.PHONY: all clean fclean re