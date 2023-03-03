# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:45:26 by mennaji           #+#    #+#              #
#    Updated: 2023/03/03 18:22:54 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = mandelbrot.c \
		julia_Set.c \
		main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fractal
OBJS = $(FILES:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): ${OBJS}
	${CC} $(OBJS) -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all
