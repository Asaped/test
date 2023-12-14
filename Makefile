NAME		=	Minishell

SRCS		=	minishell.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C gnl/
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) gnl/gnl.a
			
clean		: 
				$(RM) $(OBJS) gnl/*.o

fclean		:	clean
				$(RM) $(NAME) gnl/gnl.a

re			:	fclean all

.PHONY		:	all clean fclean re

