# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-kra <jvan-kra@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/19 15:45:22 by jvan-kra      #+#    #+#                  #
#    Updated: 2021/12/01 19:59:39 by jvan-kra      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c


HEADER = get_next_line_int.h

OBJS = ${SRCS:.c=.o}

CC = gcc

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -I. -c $< -o $@

${NAME}: ${OBJS} ${HEADER}
	${AR} rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
