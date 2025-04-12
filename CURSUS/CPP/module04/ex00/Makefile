# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 20:17:04 by daniel            #+#    #+#              #
#    Updated: 2025/03/02 10:03:17 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals
SRC = 	main.cpp \
		Animal.cpp \
		WrongAnimal.cpp \
		Cat.cpp \
		WrongCat.cpp \
		Dog.cpp
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<
	
clean: 
	$(RM) $(OBJ)

fclean: clean #recordar q cuando una regla contiene otra va en misma linea
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re