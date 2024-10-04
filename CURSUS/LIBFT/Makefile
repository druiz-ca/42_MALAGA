# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 18:59:33 by druiz-ca          #+#    #+#              #
#    Updated: 2024/01/15 12:12:03 by druiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c
BSOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

# La almoadilla sirve para comentar en vez de //
# La barra invertida \ sirve para contiuar la misma frase en la siguiente línea
# NAME es una variable y guarda en ella el nombre que tendrá el archivo que se va a crear
# en la variable SCR meto todos los archivos src para no tener que escribirlos siempre
# cuando uso las variables les tengo que poner $ delante y entre {}
# así le digo que convierta los SRC.c a .o y los guarde en la VAR OBJS
# ALL le indica que haga todo lo que hay en el make y lo "guarde" en el nueo archivo
# que va a crear el make que se llama libtf.a, cuyo nombre se guarda en la variable NAME
# le indico lo que debe compliar con CC (prog + srcs + flags)
# el -o es para que le ponga el nombre que le he dado en la variable NAME, sino le pone a.out
#luego le digo que borre los archivo objetos que ha creado ( los .o)
#borra los archivos temporales, el ejecutable, y los archivos objeto
# fuerza la recompilación de todos los archivos fuente
#el .PHONY es para que, si ya existe otro archivo con ese nombre, lo cree igualmente
# Receta = objetivo <- dependencias + comandos
# make: Nothing to be done for `all'. este error lo da cuando ya ha hecho el libtf.a
#si se quiere reahacer, se borra el libtf.a y se vuelve a hacer el make
# PRIMERO se hace el make y luego el paco
# Porque no genera los .o del bonus y aun así funciona??
# $? es la lista de dependencias más recientes
# $@ es el nombre del objetivo
# ar significa que se va a crear un archivo

# DESTINO(REGLA): REQUISITOS(ARCHIVOS: main.c ft_putchar.c)
#  		COMANDOS (gcc -c -Wall -Wextra -Werror -I. -o $@ $< main.c)
# el destino puede ser una tarea en vez de un archivo: clean, fclean, re, all, bonus