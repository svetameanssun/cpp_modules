NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES =	main.cpp \
			PmergeMe.cpp

SRC = $(SRC_FILES)

OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADERS_FILES = PmergeMe.hpp


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
	@./$(NAME) $$(shuf -i 1-3000 -n 1000)


run2:
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run run2
