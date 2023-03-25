# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 17:45:26 by mennaji           #+#    #+#              #
#    Updated: 2023/03/24 21:33:22 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = mandelbrot.c \
		julia_Set.c \
		main.c \
		draw_utils.c \
		hook.c \
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = fractal
OBJS = $(FILES:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): ${OBJS}
	${CC} $(OBJS) -o $(NAME) $(MLX)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all
