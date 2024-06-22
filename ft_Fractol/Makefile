NAME = fractol
SOURSE = main.c color.c fractal.c hook.c loop.c
OBJ = $(SOURSE:%.c=%.o)
all:$(NAME)
%.o: %.c frac.h
	cc  -Wall -Wextra -Werror -Imlx -g -c -o $@ $<

$(NAME): $(OBJ) $(SOURSE) 
	 cc $(OBJ) -Wall -Wextra -Werror -Lmlx -lmlx -framework OpenGL -framework AppKit -g -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "clean"

fclean: clean
	@/bin/rm -f $(NAME) 
	@echo "fclean"

re: fclean all