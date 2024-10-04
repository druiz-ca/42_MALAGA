NAME = philo
CC = gcc -g -Wall -Werror -Wextra

CFILES = src/main.c \
		src/check_args.c \
		src/check_args_utils.c \
		src/init_table.c \
		src/init_table_aux.c \
		src/start_dinner.c \
		src/routine.c \
		src/mutexes_check.c \
		src/times.c \
		src/routine_actions.c \
		src/finish_dinner.c \
		src/free_memory.c \
		src/monitor.c \
		src/mutexes_set.c

OFILES = $(CFILES:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(CFILES) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(OFILES)

re: fclean $(NAME)

.PHONY: all clean fclean re