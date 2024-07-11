# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:06:31 by lpittet           #+#    #+#              #
#    Updated: 2024/07/10 08:30:36 by jbarbey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c is_map_valid.c parse_map.c utils.c utils2.c parse_param.c solver.c print_answer.c read_stdin.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

DEBUG	= -fsanitize=address -g

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
