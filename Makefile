NAME = fdf
LIB = libft/libftprintf.a
INCL = ./fdfHeader.h
FLAGS = -Wall -Wextra -Werror

OBJ =   ./main.o \
        ./valid.o \
        ./message_errors.c\
        ./record_map.c\
        ./draw.c\
        ./color.c\

all: $(NAME) $(LIB)

$(NAME): $(OBJ) $(LIB)
	@make -C libft
	@gcc $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $@

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