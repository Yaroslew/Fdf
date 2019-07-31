NAME = fdf
LIB = libft/libftprintf.a
MLX = libft/minilibx/libmlx.a
INCL = fdfHeader.h
FLAGS = -Wall -Wextra -Werror

OBJ =   ./main.o \
        ./valid.o \
        ./message_errors.o\
        ./record_map.o\
        ./draw.o\
        ./color.o\
        ./output.o\

all: $(NAME) $(LIB)

$(NAME): $(OBJ) $(LIB)
	@gcc $(OBJ) $(LIB) $(MLX) -lmlx -framework OpenGL -framework AppKit -o $@

$(LIB):
	@make -C libft

edit: $(OBJ)
	@gcc $(FLAGS) -o $(OBJ)

%.o: %.c $(INCL)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all