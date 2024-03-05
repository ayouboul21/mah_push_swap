SRC = get_next_line.c get_next_line_utils.c
OBJS = ${SRC:.c=.o}
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
NAME = gnl.a


%.o: %.c get_next_line.h
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME}: ${OBJS}
		@${LIBC} ${NAME} ${OBJS}


all: ${NAME}

clean:
	@${RM} $(OBJS)

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: clean