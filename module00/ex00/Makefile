CXX = g++
STDFLAG = -std=c++98
WFLAGS = -Werror -Wextra -Wall

TARGET = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(WFLAGS) $(STDFLAG) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(WFLAGS) $(STDFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean