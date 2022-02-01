# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letumany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 15:05:58 by letumany          #+#    #+#              #
#    Updated: 2022/01/05 21:01:15 by letumany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= so_long
HEADER			= so_long.h
LIBFT_DIR		= libs/libft/
LIBFT 			= $(LIBFT_DIR)libft.a
LIBMLX_DIR 		= libs/minilibx_mms/
LIBMLX 			= $(LIBMLX_DIR)libmlx.dylib
MAKE 			= make
CLEAN 			= clean
FCLEAN 			= fclean
SRC				= src/start.c		src/map_input.c\
				src/so_long.c		src/parcer.c\
				src/keys.c			src/moves.c\
				src/utils1.c		src/sprite.c
				
				
OBJ 			= $(SRC:.c=.o)
CC				= gcc
FLAG			= -Wall -Werror -Wextra -g -O0 
FLAGMLX			= -framework OpenGL -framework AppKit
OPTION 			= -c -D GL_SILENCE_DEPRECATION 
OPTION_OBJ		= -o
DEL				= rm -rf

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTION_OBJ) $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBMLX_DIR)
	@$(CC) $(FLAG) $(OBJ)  -L $(LIBFT_DIR) -L $(LIBMLX_DIR)  -lmlx -lft $(FLAGMLX) $(OPTION_OBJ) $(NAME) 
	@tput  setaf 190 && echo "\tso_long\t\tCREATED"

.PHONY: all clean fclean re

clean:
	@$(DEL) $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	@$(DEL) $(OBJ)
	@tput setaf 45 && echo "\tALL\t\tCLEARED"

fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)
	@tput setaf 33 && echo "\tLIBS\t\tCLEARED😁"

re: fclean all
