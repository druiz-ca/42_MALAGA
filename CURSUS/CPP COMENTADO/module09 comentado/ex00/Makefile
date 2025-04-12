# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 12:56:36 by daniel            #+#    #+#              #
#    Updated: 2025/04/11 13:18:46 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= btc
CC= c++
SRC= main.cpp BitcoinExchange.cpp
FLAGS= -std=c++98 -Wall -Werror -Wextra
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