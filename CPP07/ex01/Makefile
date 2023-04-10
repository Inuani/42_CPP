NAME	= iter

CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -rf

GREEN	=   \e[92;5;118m
ORANGE	=   \e[38;5;208m
RESET	=   \e[0m

OBJ_DIR = ./obj

SRCS =	main.cpp

HDRS =	Iter.hpp

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) $^ -o $(NAME)
	@printf "$(GREEN) Executable ready.\n$(RESET)"

$(OBJ_DIR)/%.o: %.cpp $(HDRS)
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(ORANGE) Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(ORANGE) Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
