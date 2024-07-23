# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:37:34 by ecaliska          #+#    #+#              #
#    Updated: 2023/12/08 15:58:42 by ecaliska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=	cc

CFLAGS=	-Wall -Werror -Wextra

SRC=	pipex.c child_one.c child_two.c errorhandling.c pipex_utils.c

NAME= pipex

RM= rm -f

$(NAME): $(SRC)
	@echo "making all"
	@make -sC ./libft all
	@echo "."
	@make -sC ./ft_printf all
	@echo ".."
	@make -sC ./ft_fd_printf all
	@echo "..."
	@$(CC) $(CFLAG) -g -o $(NAME) $(SRC) libft/libft.a ft_printf/libftprintf.a ft_fd_printf/ft_fd_printf.a
	@echo "making done"

all: $(NAME)

clean:
	@echo "cleaning all"
	@$(RM) $(OBJ)
	@+$(MAKE) clean -sC libft
	@+$(MAKE) clean -sC ft_printf
	@+$(MAKE) clean -sC ft_fd_printf
	@echo "cleaning done"

fclean: clean
	@echo "fcleaning all"
	@$(RM) $(NAME)
	@+$(MAKE) fclean -sC libft
	@+$(MAKE) fclean -sC ft_printf
	@+$(MAKE) fclean -sC ft_fd_printf
	@echo "fcleaning done"

re:	fclean all

.PHONY: all clean fclean re