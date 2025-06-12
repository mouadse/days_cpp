NAME = ex00          # change to ex01 in the next folder
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: ; rm -f $(OBJS)
fclean: clean ; rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

