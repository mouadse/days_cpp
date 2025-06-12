NAME = ex00
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
SRCS = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: ; rm -f $(OBJS)
fclean: clean ; rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
