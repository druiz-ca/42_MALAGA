# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 19:15:39 by daniel            #+#    #+#              #
#    Updated: 2025/02/10 17:53:18 by daniel           ###   ########.fr        #
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
# es necesario hacer los .o de cada .cpp y luego linkearlos?
# -o para especificar el nombre del ejecutable, sino a.out
all:
	@$(C++) $(SRC) $(STD98) $(FLAGS) -o $(NAME)
	@./$(NAME)

re:
	all fclean

fclean:
	@rm -f $(NAME)