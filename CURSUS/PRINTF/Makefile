# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 11:08:11 by druiz-ca          #+#    #+#              #
#    Updated: 2024/02/12 12:32:48 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	= 	ft_printf.h

SRC		=	ft_printf.c	ft_ptr.c ft_ifs.c ft_hex.c 

OBJ		=	${SRC:.c=.o}

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo Compilando
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}

clean:
	@echo Borrando archivos
	${RM} ${OBJ}

fclean: clean
	@echo Borrando librería
	${RM} $(NAME)

re: fclean all  