CC = cc

FLAGS = -Wall -Werror -Wextra -lmlx -lXext -lX11

SRC = main.c checker_one.c checker_two.c error_and_free.c so_long_utils.c move_player.c read_file.c \
	check_img.c initialize.c

OBJECTS = $(SRC:.c=.o)

NAME = so_long

RM = rm -f

$(NAME): $(SRC)
	@echo "making all"
	@make -sC ./libft all
	@echo "."
	@make -sC ./ft_printf all
	@echo ".."
	@echo "..."
	@$(CC) $(FLAGS) -g -o $(NAME) $(SRC) libft/libft.a ft_printf/libftprintf.a
	@echo "making done"

all: $(NAME)

clean:
	@echo "cleaning all"
	@$(RM) $(OBJ)
	@+$(MAKE) clean -sC libft
	@+$(MAKE) clean -sC ft_printf
	@echo "cleaning done"

fclean: clean
	@echo "fcleaning all"
	@$(RM) $(NAME)
	@+$(MAKE) fclean -sC libft
	@+$(MAKE) fclean -sC ft_printf
	@echo "fcleaning done"

re: fclean all

gitpush: fclean
	@echo "pushing in github"
	@git add *
	@git commit -m 'Makfile pushing'
	@git status
	@git push

.PHONY: all clean fclean re gitpush