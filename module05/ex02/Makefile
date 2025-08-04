# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 21:22:45 by stitovsk          #+#    #+#              #
#    Updated: 2025/08/03 23:43:25 by stitovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = bureaucrat
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD
CXX = g++
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
DEP = $(OBJ:.o=.d)

TRYBLOCK_FLAGS = -DUSE_CONSTRUCTOR_TRY_BLOCK

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

TRYBLOCK:
	@echo "Cleaning log..."
	@$(RM) log.txt
	@$(MAKE) re CXXFLAGS="$(CXXFLAGS) $(TRYBLOCK_FLAGS)"
	@echo "Compiled with USE_CONSTRUCTOR_TRY_BLOCK"

.PHONY: all clean fclean re TRYBLOCK
