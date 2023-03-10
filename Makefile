# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 12:27:45 by mennaji           #+#    #+#              #
#    Updated: 2023/02/13 15:35:56 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FILES = ft_printf.c \
       ft_putstr.c \
	   ft_puthex_num.c \
	   ft_put_num_func.c \

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
