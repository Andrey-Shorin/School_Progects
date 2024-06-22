NAME = libftprintf.a

HEADER = ft_printf.h

SOURCE =  ft_strlcpy.c ft_strlen.c ft_printf_new1.c	ft_printf_new2.c \
ft_print_end.c		ft_printf_to_str1.c	ft_print_start.c	ft_printf_to_str2.c

OBJ = $(patsubst %.c, %.o, $(SOURCE))

all:$(NAME)

$(NAME): $(OBJ) $(HEADER) 
	ar rc $(NAME) $(SOURCE:.c=.o)


%.o: %.c ft_printf.h
	@cc -Wall -Wextra -Werror -c -o $@ $<
	@echo ".\c"

clean:
	@/bin/rm -f $(SOURCE:.c=.o)
	@/bin/rm -f $(SOURCE_BONUS:.c=.o)
	@echo "clean"

fclean: clean
	@/bin/rm -f $(NAME) libft.so
	@echo "fclean"

re: fclean all

so:
	gcc -nostartfiles -fPIC -Wall -Wextra -Werror  $(SOURCE)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
	
