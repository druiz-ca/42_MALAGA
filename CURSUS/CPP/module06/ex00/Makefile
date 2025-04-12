# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 13:05:16 by druiz-ca          #+#    #+#              #
#    Updated: 2025/04/03 12:57:19 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar
SRC = 	main.cpp ScalarConverter.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re