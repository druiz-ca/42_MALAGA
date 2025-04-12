# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/06 11:10:06 by druiz-ca          #+#    #+#              #
#    Updated: 2025/04/06 12:27:00 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= mutanstack
CC= c++
FLAGS= -std=c++98 -Wall -Werror -Wextra
SRC= main.cpp
OBJ= $(SRC:.cpp=.o)
RM= rm -f

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re