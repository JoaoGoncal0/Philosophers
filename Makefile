NAME = philo.a

CC = cc -Wall -Werror -Wextra

RM = rm -f

SRCS =	free_functions.c \
		init_program.c \
		main.c \
		parsing.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ) 
			$(CC) $(OBJ) -o $(NAME)
			@echo "$(NAME) created"

clean:
			$(RM) $(OBJ)
	
fclean:		clean
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:		all clean fclean re