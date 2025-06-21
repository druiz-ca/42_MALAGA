# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 13:55:11 by druiz-ca          #+#    #+#              #
#    Updated: 2025/02/23 11:50:38 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp = .o)

all: $(NAME)

# REGLA PARA EL EJECUTABLE
$(NAME): $(OBJ) # patron de dependencia: el nombre del ejecutable depende de los .o
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

#REGLA PARA LOS ARCHIVOS .o
%.o: %.cpp # patron de dependencia: dice que cada .c depende de un .h
	$(CC) $(FLAGS) -c -o $@ $<
			
clean:
	$(RM) $(NAME) # si pongo $(OBJ) borra los .cpp??

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
	#le dice a make que estos targets no son archivos sino comandos para 
	#que no se confunda si hay un archivo con el mismo nombre

