# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 19:15:39 by daniel            #+#    #+#              #
#    Updated: 2025/02/11 21:28:59 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = FragTrap

SRC = 	main.cpp \
		FragTrap.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

C++ = c++

FLAGS = -Wall -Wextra -Werror

STD98 = -std=c++98

all:
	@$(C++) $(SRC) $(STD98) $(FLAGS) -o $(NAME)
	@./$(NAME)

re:
	all fclean

fclean:
	@rm -f $(NAME)