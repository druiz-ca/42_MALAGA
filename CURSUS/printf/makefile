# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 13:11:08 by druiz-ca          #+#    #+#              #
#    Updated: 2024/02/07 12:58:48 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = libftprintf.c ft_itoa.c ft_uitoa.c ft_hexitoa.c ft_ifs.c ft_if_x.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


#NAME = libftprintf.a: 
#Define una variable NAME que contiene el nombre del archivo de la biblioteca que se creará.
#SRCS = libftprintf.c ft_itoa.c ft_uitoa.c ft_hexitoa.c ft_ifs.c ft_if_x.c: 
#Define una variable SRCS que contiene una lista de los archivos de código fuente que se compilarán.
#OBJS = $(SRCS:.c=.o): 
#Define una variable OBJS que contiene una lista de los archivos de objeto que se generarán a partir de los archivos de código fuente.
#CC = gcc: 
#Define una variable CC que contiene el nombre del compilador que se utilizará.
#CFLAGS = -Wall -Wextra -Werror: 
#Define una variable CFLAGS que contiene las opciones que se pasarán al compilador.
#all: $(NAME): 
#Define una regla all que depende de $(NAME). Cuando ejecutas make sin argumentos, se ejecuta la regla all.
#$(NAME): $(OBJS): 
#Define una regla para crear $(NAME) a partir de $(OBJS). Utiliza el comando ar para crear una biblioteca estática a partir de los archivos de objeto.
#%.o: %.c: 
#Define una regla de patrón que dice cómo convertir un archivo .c en un archivo .o. Utiliza el compilador $(CC) para compilar el archivo de código fuente en un archivo de objeto.
#clean:: 
#Define una regla clean que elimina todos los archivos de objeto.
#fclean: clean: 
#Define una regla fclean que depende de clean y también elimina $(NAME).
#re: fclean all: 
#Define una regla re que depende de fclean y all. Esto permite limpiar todo y luego reconstruir todo con un solo comando.
#.PHONY: all clean fclean re: 
#Declara que all, clean, fclean y re son objetivos ficticios, lo que significa que no se corresponden con archivos reales.
