CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -O1 -fsanitize=address
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
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
