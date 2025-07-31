# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 21:22:45 by stitovsk          #+#    #+#              #
#    Updated: 2025/07/28 16:15:27 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = bureaucrat
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

#SRC = $(shell find . -name "*.cpp") I might have used this, but I think it is against the norm
SRCDIR = src/
OBJDIR = obj/
SRCFILES = AForm.cpp \
	Bureaucrat.cpp \
	ExceptionsFile.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	main.cpp

SRC = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ = $(addprefix $(OBJDIR), $(SRCFILES:.cpp=.o))

TRYBLOCK_FLAGS = -DUSE_CONSTRUCTOR_TRY_BLOCK

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

TRYBLOCK: CXXFLAGS += $(TRYBLOCK_FLAGS)
TRYBLOCK:
	@echo "Cleaning log..."
	@$(RM) log.txt
	@$(MAKE) re CXXFLAGS="$(CXXFLAGS)"
	@echo "Compiled with USE_CONSTRUCTOR_TRY_BLOCK"
TRYBLOCK: re
	@echo "Compiled with USE_CONSTRUCTOR_TRY_BLOCK"

.PHONY: all clean fclean re TRYBLOCK
