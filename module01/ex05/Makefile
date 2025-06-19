# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 23:12:56 by stitovsk          #+#    #+#              #
#    Updated: 2025/06/19 23:12:58 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = harl
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = g++
SRC = main.cpp \
	Harl.cpp


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