# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 16:49:02 by owalsh            #+#    #+#              #
#    Updated: 2022/05/10 18:08:58 by owalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_itoa.c \
		ft_puthex.c

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
