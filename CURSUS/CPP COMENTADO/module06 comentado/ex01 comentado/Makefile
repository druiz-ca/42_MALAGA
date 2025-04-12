# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 10:07:54 by daniel            #+#    #+#              #
#    Updated: 2025/04/02 10:19:50 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#si se usa = es una variable, si se usa : es una regla
NAME= serializer
CC= c++
FLAGS= -std=c++98 -Wall -Werror -Wextra
SRC= main.cpp Serializer.cpp
OBJ= $(SRC:.cpp=.o)
RM= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

re: fclean all

clean: 
	$(RM) $(OBJ)
 
fclean: clean
	$(RM) $(NAME)


.PHONY: all re clean fclean