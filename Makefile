SRC = 	operations.c push_swap.c sorting.c \
		stack_utils.c stack_utils2.c stack_utils3.c targets.c
SRC_BONUS = checker_bonus.c checker_utils_bonus.c \
			operations_bonus.c checker_utils2_bonus.c \
			parsing_bonus.c
OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:_bonus.c=_bonus.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
NAME = push_swap
NAME_BONUS = checker
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
GNL_DIR = libs/get_next_line
LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/gnl.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c -o $@ $<

%_bonus.o: %_bonus.c checker_bonus.h get_next_line.h
	@$(CC) $(CFLAGS) -c -o $@ $<

all: pre ${NAME}

${NAME}: ${OBJS} $(LIBFT_LIB) $(PRINTF_LIB)
		@echo "Linking with Libft and Ftprintf..."
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "Finished"

${NAME_BONUS}: ${OBJS_BONUS} ${GNL} $(LIBFT_LIB) $(PRINTF_LIB)
		@echo "Compiling Bonus..."
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "Finished"

pre:
	@echo "Compiling..."
	@echo "Building Libft..."
	@cd $(LIBFT_DIR) && make
	@echo "Building Ftprintf..."
	@cd $(PRINTF_DIR) && make
	@echo "Done"

pre_bonus:
	@echo "Compiling..."
	@echo "Building Libft..."
	@cd $(LIBFT_DIR) && make
	@echo "Building Ftprintf..."
	@cd $(PRINTF_DIR) && make
	@echo "Building Get_next_line..."
	@cd $(GNL_DIR) && make
	@echo "Done"

clean:
	@echo "Cleaning..."
	@${RM} $(OBJS) ${OBJS_BONUS}
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "Finished"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

bonus: pre_bonus ${NAME_BONUS}

.PHONY: clean