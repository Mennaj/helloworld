# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 12:27:45 by mennaji           #+#    #+#              #
#    Updated: 2023/02/12 15:08:58 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FILES = printf.c \
       ft_pustr.c \
	   ft_put_pointer.c \
	   ft_putuns.c \
	   ft_puthex_num.c \
	   ft_putchar.c \

OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
HDRS = ft_printf.h

.c.o = ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
