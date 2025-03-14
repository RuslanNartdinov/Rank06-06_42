NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

eval: all clean