# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 21:22:45 by stitovsk          #+#    #+#              #
#    Updated: 2025/08/15 19:37:51 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = converter
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD
CXX = g++
RM = rm -f

#SRC = $(shell find . -name "*.cpp") I might have used this, but I think it is against the norm
SRCDIR = src/
OBJDIR = obj/
SRCFILES = LiteralDetector.cpp \
	ScalarConverter.cpp \
	main.cpp

SRC = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ = $(addprefix $(OBJDIR), $(SRCFILES:.cpp=.o))
DEP = $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET) $(DEP)
re: fclean all

.PHONY: all clean fclean re
