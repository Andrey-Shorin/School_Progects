MNAME = libft.a

HEADER = libft.h

SOURCE =  ft_isalnum.c   ft_isdigit.c   ft_memcmp.c ft_memset.c ft_strlcpy.c \
ft_strnstr.c   ft_toupper.c    ft_isalpha.c   ft_isprint.c   ft_memcpy.c   \
ft_strchr.c    ft_strlen.c    ft_strrchr.c  ft_bzero.c   ft_isascii.c  \
ft_memchr.c    ft_memmove.c   ft_strlcat.c   ft_strncmp.c   ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

SOURCE_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = $(patsubst %.c, %.o, $(SOURCE))
OBJ2 = $(patsubst %.c, %.o, $(SOURCE_BONUS))
all:$(NAME) 

$(NAME): $(OBJ) $(HEADER) 
	ar rc $(NAME) $(SOURCE:.c=.o)


%.o: %.c libft.h
	@gcc -Wall -Wextra -Werror -c -o $@ $<
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
	
bonus:$(OBJ2) $(OBJ) $(HEADER) 
	ar rc $(NAME) $(SOURCE_BONUS:.c=.o) $(SOURCE:.c=.o)

