# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kezann <kezann@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 19:50:58 by akezanna          #+#    #+#              #
#    Updated: 2021/01/05 22:26:44 by kezann           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
		ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o\
		ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o\
		ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o\
		ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmapi.o\
		ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o\
		ft_tolower.o ft_toupper.o ft_strlcpy.o get_next_line.o

all: $(NAME)

$(NAME): $(SRC)
	ar rc $(NAME) $(SRC)

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
