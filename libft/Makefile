# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 12:38:23 by hrema             #+#    #+#              #
#    Updated: 2020/06/11 11:07:42 by hrema            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME=libft.a

FLAGS=-Wall -Wextra -Werror

SRCS_MAIN=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)

SRCS_BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_BONUS=$(SRCS_BONUS:%.c=%.o)

INCLUDES=./

all: $(NAME)

$(NAME): $(OBJS_MAIN)
	ar rc $(NAME) $(OBJS_MAIN)
	ranlib $(NAME)

%.o: %.c libft.h
	gcc -c $(FLAGS) -I$(INCLUDES) -o $@ $<

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS_MAIN) $(OBJS_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

