# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 11:59:33 by druiz-ca          #+#    #+#              #
#    Updated: 2025/03/24 12:36:49 by daniel           ###   ########.fr        #
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

OBJ = $(SRCS:.cpp=.o) #solo crea una lista de nombres .o


#Regla que define como se debe generar los archivos objeto
%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<
	# cada vez que se genere un .o se ejecutara esta regla

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)
#borra los archivos .o

#si el comentario lo tabulo dentro de la regla lo imprime!!
fclean: clean
	$(RM) $(NAME)
	#borra los archivos .o y el ejecutable

re: fclean all

.PHONY: all clean fclean re