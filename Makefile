# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 14:51:15 by ghaas             #+#    #+#              #
#    Updated: 2018/03/16 14:51:21 by ghaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs
SRC_NAME = init_env.c\
		init_img.c\
		init_param.c\
		draw_fractals.c\
		draw_fractals2.c\
		key_functions.c\
		function_event.c\
		main.c\
		mouse_hook.c\
		print_menu.c\
		select_fractals.c\

CPPFLAGS = -I libft/includes -I includes -I mlx/

NAME = Fractol

LOGIN = ghaas

CC = gcc

CFLAGS = -Werror -Wall -Wextra

LIBFT = libft/libft.a

MLX = minilibx_macos/libmlx.a

FW = -framework OpenGL -framework AppKit

OBJ = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

all: $(NAME)

$(NAME):
		@make -C libft/
		@make -C minilibx_macos/
		@$(CC) $(CFLAGS) -c $(SRC) $(CPPFLAGS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(FW)
		@echo "\033[38;5;32m  [$(NAME)]	Compiled."
		@echo "\033[34m"
		@echo "\033[38;5;24m  MMMºººAMV      MMºººMM        MMºººMM    MMºººMm"
		@echo " MM             MM     MM'     MM     MM   MM    Mm"
		@echo "\033[38;5;25m MM            MM       MM'   MM       MM  MM     mm"
		@echo " MM            MM       MM'   MM       MM  MM      M"
		@echo "\033[38;5;26m MM   AMVMMAMV MM       MM'   MM       MM  MM     mm"
		@echo " MM      MM     MM     MM'     MM     MM   MM    Mm"
		@echo "\033[38;5;27m  AMVmmmmMM      MMwwwMM        MMwwwMM    MMwwwMM "
		@echo ""
		@echo "\033[38;5;32m [2018]                    [${LOGIN}]"
		@echo ""

clean:
		@make clean -C libft/
		@make clean -C minilibx_macos/
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re: fclean all