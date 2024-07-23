CC=	cc

CFLAGS=	-Wall -Werror -Wextra

SRC=	ft_printf.c ft_putnbr.c ft_unsigned_putnbr.c \
		print.c str.c len.c adress.c hexadecimal.c

OBJ= $(SRC:.c=.o)

NAME= libftprintf.a

RM= rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean && make all

.PHONY: all clean fclean re
