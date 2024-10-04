NAME = push_swap
CC = gcc -g -Wall -Wextra -Werror 
CFILES = src/push_swap.c \
		src/ft_split.c \
		src/utils.c \
		src/rotate.c \
		src/gets.c \
		src/sort.c \
		src/rotate_functions.c \
		src/rev_rotate_functions.c \
		src/push_and_swap.c \
		src/ps_utils2.c \
		src/ps_utils.c \
		src/main.c \

OFILES = $(CFILES:.c=.o)

# ESTO ES PARA QUE SE COMPILAN LOS ARCHIVOS .c A .o
$(NAME): $(OFILES)

	@$(CC) $(CFILES) -o $(NAME)
# EL @ es para que no muestre el comando que se ejecuta
%.o: %.c
	$(CC) -c $< -o $@
# ESTO ES PARA QUE SE COMPILAN LOS ARCHIVOS .c A .o
# EL $< es para que tome el archivo .c
# EL $@ es para que tome el archivo .o
all: $(NAME)

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(OFILES)

re: fclean $(NAME)

.PHONY: all clean fclean re
