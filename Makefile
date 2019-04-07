NAME = fdf
LIB = libft/libft.a
INCL = ./header.h
FLAGS = -Wall -Wextra -Werror

OBJ = ./main.o ./valid.o ./standart_output.o ./record_map.o ./img_operation.o ./draw_line.o

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
#	@make -C libft
	@cc $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $@

edit: $(OBJ)
	@gcc $(FLAGS) -o $(OBJ)

%.o: %.c $(INCL)

clean:
#	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
#	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all