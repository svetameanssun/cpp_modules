TARGET = zombiehorde

CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = g++

SRC = main.cpp \
	Zombie.cpp \
	zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re