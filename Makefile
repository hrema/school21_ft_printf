# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 11:08:42 by hrema             #+#    #+#              #
#    Updated: 2020/07/14 13:45:31 by hrema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		initialization_number.c \
		get_struct.c \
		len_numbers.c \
		put_numbers.c \
		print_c.c \
		print_s.c \
		print_p.c \
		print_di.c \
		print_u.c \
		print_x.c \
	
OBJS = $(SRCS:%.c=%.o)

INCLUDES = ./

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAGS) -I$(INCLUDES) -o $@ $<

clean:
	make clean -C ./libft
	/bin/rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)

bonus: all

re: fclean all
