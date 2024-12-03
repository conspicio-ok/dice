NAME	=	prog
CC		=	cc
WFLAGS	=	-Wall -Werror -Wextra
SRC		=	*.c
OBJ		=	$(SRC:.c=.o)
RM		=	rm -f

$(NAME):	$(OBJ)
	@$(CC) $(WFLAGS) $^ -o $(NAME)

all:		$(NAME)

.c.o:
	@$(CC) $(WFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJ)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all
