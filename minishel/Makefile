NAME = minishell

HEADER = minishell.h

SOURCE_G = gnl/get_next_line_utils.c gnl/get_next_line.c 

SOURCE = main/main.c main/delit.c main/env1.c main/execve.c main/input.c main/checker.c main/in.c
SOURCE_L =  libft/ft_isalnum.c   libft/ft_isdigit.c   libft/ft_memcmp.c libft/ft_memset.c libft/ft_strlcpy.c \
libft/ft_strnstr.c   libft/ft_toupper.c    libft/ft_isalpha.c   libft/ft_isprint.c   libft/ft_memcpy.c   \
libft/ft_strchr.c    libft/ft_strlen.c    libft/ft_strrchr.c  libft/ft_bzero.c   libft/ft_isascii.c  \
libft/ft_memchr.c    libft/ft_memmove.c   libft/ft_strlcat.c   libft/ft_strncmp.c   libft/ft_tolower.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c \
libft/ft_substr.c libft/ft_strjoin.c libft/ft_strjoin2.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c \
libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c 

SOURCE_P =   print/ft_printf_new1.c	print/ft_printf_new2.c \
print/ft_print_end.c		print/ft_printf_to_str1.c	print/ft_print_start.c	print/ft_printf_to_str2.c

OBJ = $(patsubst %.c, %.o, $(SOURCE)) $(patsubst %.c, %.o, $(SOURCE_G)) $(patsubst %.c, %.o, $(SOURCE_P)) $(patsubst %.c, %.o, $(SOURCE_L))

all:$(NAME) 

$(NAME): $(OBJ) $(HEADER) 
	@cc -Wall -Wextra -Werror -g -o $(NAME) $(SOURCE:.c=.o)  $(SOURCE_G:.c=.o) $(SOURCE_P:.c=.o) $(SOURCE_L:.c=.o)
	@echo "done"

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror -g -c -o $@ $<
	@echo ".\c"

clean:
	@/bin/rm -f $(SOURCE:.c=.o)  $(SOURCE_G:.c=.o) $(SOURCE_P:.c=.o) $(SOURCE_L:.c=.o)
	@/bin/rm -f 
	@echo "clean"

fclean: clean
	@/bin/rm -f $(NAME) checker
	@echo "fclean"

re: fclean all



