
CC = cc

NAME = philo

CFLAGS = -Wall -Werror -Wextra

SRC = main.c utility.c utility2.c single.c init.c actions.c printing.c routine.c thread.c

RM = rm -f

OBJ = $(SRC:.c=.o)

COLOR_GREEN = \033[0;32m
COLOR_RED = \033[0;31m
COLOR_BLUE = \033[0;34m
COLOR_END = \033[0m

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	@echo "$(COLOR_RED)CLEAINING ALL$(COLOR_END)"
	@$(RM) $(OBJ)
	@echo "$(COLOR_GREEN)CLEANING DONE$(COLOR_END)"

clean2:
	@$(RM) $(OBJ)

fclean: clean2
	@echo "$(COLOR_RED)FCLEANING ALL$(COLOR_END)"
	@$(RM) $(NAME)
	@echo "$(COLOR_GREEN)FCLEANING DONE$(COLOR_END)"

re: fclean all

gitpush: fclean
	@echo "$(COLOR_RED)pushing in github$(COLOR_END)"
	@git add *
	@git commit -m "Makefile pushing"
	@git push
	@echo "$(COLOR_GREEN)PUSHED TO YOUR GITHUB$(COLOR_END)"

.PHONY: all clean clean2 fclean re gitpush
