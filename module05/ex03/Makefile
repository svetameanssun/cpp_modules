# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 21:22:45 by stitovsk          #+#    #+#              #
#    Updated: 2025/08/12 17:01:52 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = bureaucrat
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = g++
RM = rm -f

#SRC = $(shell find . -name "*.cpp") I might have used this, but I think it is against the norm
SRCDIR = src/
OBJDIR = obj/
SHRUBERYF = _shrubbery
SRCFILES = AForm.cpp \
	Bureaucrat.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	Intern.cpp \
	main.cpp

SRC = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ = $(addprefix $(OBJDIR), $(SRCFILES:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)
	$(RM) *$(SHRUBERYF)
re: fclean all

.PHONY: all clean fclean re
