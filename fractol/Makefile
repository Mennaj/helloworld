# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:45:26 by mennaji           #+#    #+#              #
#    Updated: 2023/02/28 17:47:04 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o = ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all
