NAME = containers
NAME_FT = ft_containers
NAME_STD = std_containers
.cppf = main.cpp
.of = $(.cppf:%.cpp=%.o)
.hppf = $(wildcard *.hpp)
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
CXX = c++
BLUE =`tput setaf 045`
GREEN =`tput setaf 190`
RESET =`tput sgr0`

all: $(NAME)

$(NAME): $(.of) $(.hppf)
	$(CXX) $(.of) -o $(NAME_STD)
	$(CXX) $(.of) -D FT=1 -o $(NAME_FT)

clean:
	@rm -rf $(.of)

fclean: clean
	@rm -rf $(NAME_FT) $(NAME_STD)

re: fclean $(NAME)

run: $(NAME)
	@echo "	     ${BLUE} ____ ____ "
	@echo "	     ||${GREEN}F${BLUE} |||${GREEN}T${BLUE} ||"
	@echo "	     ||__|||__||"
	@echo "	     |/__\|/__\|${RESET}"
	@./ft_containers 
	@echo "	   ${BLUE} ____ ____ ____ "
	@echo "	   ||${GREEN}S${BLUE} |||${GREEN}T${BLUE} |||${GREEN}D${BLUE} ||"
	@echo "	   ||__|||__|||__||"
	@echo "	   |/__\|/__\|/__\|${RESET}"
	@./std_containers 