CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -O0 -g3
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ClapTrap

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
