# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 09:52:03 by daniel            #+#    #+#              #
#    Updated: 2025/02/23 17:20:00 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra
SRC = 	main.cpp \
		Animal.cpp \
		Brain.cpp \
		Cat.cpp \
		Dog.cpp 
RM = rm -f
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re