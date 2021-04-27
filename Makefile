# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 17:39:19 by akezanna          #+#    #+#              #
#    Updated: 2021/03/22 10:43:33 by akezanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_LIB = -lmlx -framework OpenGL -framework AppKit -lm
MLX_LIB_LINUX = -lmlx -lXext -lX11 -lm -lbsd
LIBFT =	./libft/libft.a
LIBFT_DIR =	./libft

OBJCUB = 	srcs/drawing/raycasting.o ./srcs/drawing/textures.o \
			srcs/events/camera.o srcs/events/keyhook.o srcs/events/movement.o\
			srcs/parsing/parse.o srcs/parsing/get_textures.o srcs/parsing/get_sprite.o \
			srcs/parsing/get_resolution.o  srcs/parsing/check_map_layout.o \
			srcs/parsing/map_utiles.o srcs/parsing/utiles.o \
			srcs/drawing/raycast_utiles.o srcs/parsing/files_ext_check.o\
			./srcs/drawing/sprite.o ./srcs/drawing/savescreen.o\
			srcs/parsing/ceil_and_floor.o srcs/parsing/parse_utiles.o check_args.o my_cub3d.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJCUB)
		$(CC) $(OBJCUB) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(LIBFT): force
	make -C $(LIBFT_DIR)

force:

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJCUB)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re:
	make fclean
	make

