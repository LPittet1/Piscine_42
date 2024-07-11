SRCS		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS		= ${SRC:.c=.o}

HEADERS		= ./includes/ft.h

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o		= ${CC} ${CFLAGS} -c $< -o ${<:.c-.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${HEADERS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
