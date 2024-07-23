CC=	cc

CFLAGS=	-Wall -Werror -Wextra -g

SRC=	ft_fd_printf.c ft_fd_putnbr.c ft_fd_unsigned_putnbr.c \
		fd_print.c fd_str.c fd_len.c fd_adress.c fd_hexadecimal.c

OBJ= $(SRC:.c=.o)

NAME= ft_fd_printf.a

RM= rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.cc
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean && make all

.PHONY: all clean fclean re
