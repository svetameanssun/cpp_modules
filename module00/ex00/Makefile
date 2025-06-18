# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 11:48:01 by stitovsk          #+#    #+#              #
#    Updated: 2025/06/18 11:48:02 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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