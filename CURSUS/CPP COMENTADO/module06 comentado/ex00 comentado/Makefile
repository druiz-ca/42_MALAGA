# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 13:05:16 by druiz-ca          #+#    #+#              #
#    Updated: 2025/03/30 14:19:57 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar
SRC = 	main.cpp ScalarConverter.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(NAME)

#otra forma más sencilla de hacer la regla de los .o sin redundancia
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re