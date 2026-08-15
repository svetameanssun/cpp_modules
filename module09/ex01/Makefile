NAME = RPN

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES =	main.cpp \
			RPN.cpp

SRC = $(SRC_FILES)

OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADERS_FILES = RPN.hpp


HEADERS = $(HEADERS_FILES)


all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run:
	@./$(NAME)

run2:
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run run2