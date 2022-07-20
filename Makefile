NAME = containers
.cppf = main.cpp
.of = $(.cppf:%.cpp=%.o)
.hppf = $(wildcard *.hpp)
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
CXX = c++

all: $(NAME)

$(NAME): $(.of) $(.hppf)
	$(CXX) $(.of) -o $(NAME)

clean:
	@rm -rf $(.of)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)
