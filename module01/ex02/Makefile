# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 00:47:19 by stitovsk          #+#    #+#              #
#    Updated: 2025/06/19 00:47:20 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = brain
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = g++
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o:%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
