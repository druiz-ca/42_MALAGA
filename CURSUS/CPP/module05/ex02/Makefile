# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 11:59:33 by druiz-ca          #+#    #+#              #
#    Updated: 2025/03/30 12:05:01 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRCS = 	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonform.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp

CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.cpp=.o) 

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