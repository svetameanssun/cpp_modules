TARGET = phonebook


CPPFLAGS = -Wall -Werror -Wextra -std=c++98
#DEPFLAGS = -MMD -MP
CXX = g++

SRC = main.cpp \
		phonebook.cpp \
		contact.cpp \
		color.cpp

OBJ = $(SRC:.cpp=.o)

#DEP = $(OBJ:.o=.d)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(TARGET)
	rm -f $(OBJ)
	
#-include $(DEP)

%.o:%.cpp
	$(CXX)  $(CPPFLAGS)  -c $< -o $@

phonebook.o : phonebook.hpp

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(TARGET)

re:fclean all
	

.PHONY: all clean fclean re



