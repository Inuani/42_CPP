NAME	= brain

CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -rf
MKDIR	= mkdir -p

GREEN	= \e[92;5;118m
ORANGE	= \e[38;5;208m
RESET	= \e[0m

SRC		= main.cpp
OBJ_DIR	= obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)Executable ready.$(RESET)\n"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(ORANGE)Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(ORANGE)Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re