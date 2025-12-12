NAME = Claptrap
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3
CC = c++
SRC = main.cpp \
	ClapTrap.cpp \

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -o $@ -c $<

-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re