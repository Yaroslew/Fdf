# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 14:15:40 by hharrold          #+#    #+#              #
#    Updated: 2019/04/25 14:15:43 by hharrold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ./src/main.c ./src/valid.c ./src/message_errors.c ./src/record_map.c \
		./src/draw.c ./src/color.c ./src/output.c ./src/image_operations.c

HEAD = ./includes

WWW = -Wall -Wextra -Werror

OBG = ./obj/*.o

LFT = libft

MLX = minilibx_macos

all: $(NAME)

$(NAME):

		@mkdir obj
		@make -C $(LFT) re
		# @make -C $(MLX) re
		@gcc \
		-I $(HEAD) \
		-c $(SRC)
		@mv *.o obj/	
		@gcc \
		$(LFT)/libftprintf.a $(MLX)/libmlx.a \
		-lmlx -framework OpenGL -framework AppKit \
		-I $(HEAD) $(OBG) -o $(NAME) 
		@echo Compiled $(NAME)!
		# dont forget about FLAG COMPILE

# edit: $(OBJ)
# 	@gcc -o $(OBJ)

# %.o: %.c $(INCL)
	
clean:
		@rm -rf obj
		@make -C $(LFT) fclean

fclean: clean
		@rm -rf $(NAME)

re: fclean all


# NAME = fdf
# LIB = libft/libftprintf.a
# MLX = libft/libmlx.a
# INCL = fdfHeader.h
# FLAGS = -Wall -Wextra -Werror

# OBJ =   ./main.o \
#         ./valid.o \
#         ./message_errors.o\
#         ./record_map.o\
#         ./draw.o\
#         ./color.o\
#        # ./output.o\

# all: $(NAME) $(LIB)

# $(NAME): $(OBJ) $(LIB)
# 	@gcc $(OBJ) $(LIB) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

# $(LIB):
# 	@make -C libft

# edit: $(OBJ)
# 	@gcc $(FLAGS) -o $(OBJ)

# %.o: %.c $(INCL)

# clean:
# 	@make clean -C libft
# 	@rm -f $(OBJ)

# fclean: clean
# 	@make fclean -C libft
# 	@rm -f $(NAME)

# re: fclean all