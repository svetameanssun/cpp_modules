# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 20:30:49 by stitovsk          #+#    #+#              #
#    Updated: 2025/06/18 20:30:50 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = zombie

SRC = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Zombie.o: Zombie.hpp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re 

