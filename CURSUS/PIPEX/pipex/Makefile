NAME = pipex
CC = gcc -g -Wall -Wextra -Werror
# el -g es para que se pueda debuggear
CFILES  = src/pipex.c \
		src/checks.c \
		src/free_functions.c \
		src/pipex_utils.c \

LIBFT = libft/libft.a
PRINTF = PRINTF/libftprintf.a


OFILES  = $(CFILES:.c=.o)
# el make -s es para que no muestre los comandos que se ejecutan
# el -C es para cambiar de directorio
# el -o es para que el archivo se llame igual que el directorio
# hacer make -s -C libft para que desde este makefile se ejecute el makefile de la libreria
$(NAME): $(OFILES)
	make -s -C libft 
	make -s -C PRINTF
	@$(CC) $(CFILES) $(LIBFT) $(PRINTF) -o $(NAME)
# primero se compilan los archivos del directorio actual y luego se compilan los archivos de la libreria
%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

clean:
	make -s -C libft clean
	make -s -C PRINTF clean
	rm -f $(OFILES)

fclean:
	make -s -C libft fclean
	make -s -C PRINTF fclean
	rm -f $(OFILES)

re: fclean $(NAME)

.PHONY: all clean fclean re