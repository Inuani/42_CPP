#!/bin/bash

if [ -z "$1" ]; then
	echo "Usage: $0 ClassName"
	exit 1
fi

CLASS_NAME="$1"

# Create Class.hpp
cat > "${CLASS_NAME}.hpp" <<EOF
#include <iostream>

#ifndef ${CLASS_NAME}_HPP
# define ${CLASS_NAME}_HPP

class ${CLASS_NAME} {
public:
	${CLASS_NAME}();
	${CLASS_NAME}(const ${CLASS_NAME}& src);
	~${CLASS_NAME}();

	${CLASS_NAME}& operator=(const ${CLASS_NAME}& rhs);

private:

};

#endif
EOF

# Create main.cpp
cat > "main.cpp" <<EOF
#include <iostream>
#include "${CLASS_NAME}.hpp"

int main( void )
{
}
EOF

# Create Class.cpp
cat > "${CLASS_NAME}.cpp" <<EOF
#include "${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}()
{
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME} &src)
{
}

${CLASS_NAME}::~${CLASS_NAME}()
{
}
EOF

# Create Makefile
cat > "Makefile" <<EOF
NAME	= ${CLASS_NAME}

CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -rf

GREEN	=   \e[92;5;118m
ORANGE	=   \e[38;5;208m
RESET	=   \e[0m

OBJ_DIR = ./obj

SRCS =	main.cpp \
		${CLASS_NAME}.cpp

HDRS =	${CLASS_NAME}.hpp

OBJS = \$(patsubst %.cpp,\$(OBJ_DIR)/%.o,\$(SRCS))

all: \$(NAME)

\$(NAME): \$(OBJS)
	@\$(CXX) \$(FLAGS) \$^ -o \$(NAME)
	@printf "\$(GREEN) Executable ready.\n\$(RESET)"

\$(OBJ_DIR)/%.o: %.cpp \$(HDRS)
	@mkdir -p \$(OBJ_DIR)
	@\$(CXX) \$(FLAGS) -c \$< -o \$@

clean:
	@\$(RM) \$(OBJ_DIR)
	@printf "\$(ORANGE) Object files removed.\$(RESET)\n"

fclean: clean
	@\$(RM) \$(NAME)
	@printf "\$(ORANGE) Executable removed.\$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
EOF

echo "Files created: ${CLASS_NAME}.hpp, main.cpp, ${CLASS_NAME}.cpp, Makefile"
