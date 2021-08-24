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

SRCS		= $(shell find "." -name "*c")
OBJS		= ${SRCS:.c=.o}
NAME		= pipex.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${AR} pipex.a ${OBJS}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o