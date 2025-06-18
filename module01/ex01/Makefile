# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 00:46:04 by stitovsk          #+#    #+#              #
#    Updated: 2025/06/19 00:46:05 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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