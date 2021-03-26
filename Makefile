CC	=	gcc
NAME =	my_crd
SRC	=	Main.c \
		my_print.c \
		my_arg.c \
		my_list.c \
		convert.c
OBJ =	$(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -std=c11

RM 	=	rm -f


$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJ)

		

fclean:			clean
		$(RM) $(NAME)

re: 	fclean all
