# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 17:37:23 by daniel            #+#    #+#              #
#    Updated: 2025/04/04 18:00:15 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= easyfind
CC= c++
FLAGS= -std=c++98 -Wall -Werror -Wextra
SRC= main.cpp
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