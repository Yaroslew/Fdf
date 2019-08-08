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
LIB = libft/libftprintf.a
MLX = libft/libmlx.a
INCL = fdfHeader.h
FLAGS = -Wall -Wextra -Werror
SRC =     ./src/main.c\
          ./src/valid.c\
          ./src/message_errors.c\
          ./src/record_map.c\
          ./src/draw.c\
          ./src/color.c\
          ./src/output.c\
          ./src/controller.c\
          ./src/image_operations.c\
          ./src/output_sec.c\
          ./src/pre_draw.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc $(SRC) $(LIB) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

$(LIB):
	@make -C libft

$(OBJ): %.o: %.c
	@gcc $(FLAGS) -c $< -I $(INCL) -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all