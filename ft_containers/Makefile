NAME		=	test
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98


SRC	=	main2.cpp 
HEAD = map.hpp _r_b_tree.hpp iterator_trails.hpp reverse_iterator.hpp set.hpp stack.hpp vector.hpp
OBJ	=	$(SRC:.cpp=.o)

%.o: %.cpp $(HEAD) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -f $(OBJ) 


fclean: clean
	rm -f   $(NAME)


re: fclean all
