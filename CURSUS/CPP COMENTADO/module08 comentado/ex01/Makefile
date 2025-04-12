# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 11:14:37 by druiz-ca          #+#    #+#              #
#    Updated: 2025/04/05 11:19:55 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= span
CC= c++
FLAGS= -std=c++98 -Wall -Wextra -Werror
SRC= main.cpp Span.cpp
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

.PHONY: all clean flcean re