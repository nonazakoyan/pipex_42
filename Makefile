# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 16:57:57 by nozakoya          #+#    #+#              #
#    Updated: 2021/08/22 16:58:05 by nozakoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = ${shell find "." -name "*.c"}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} -L. ${SRCS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
