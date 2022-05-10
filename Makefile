# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 16:49:02 by owalsh            #+#    #+#              #
#    Updated: 2022/05/09 19:21:02 by owalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror 
SRC = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_itoa.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

%.o : %.c
	$(CC) -c $^

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
