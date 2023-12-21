BRAIN		=	Brain

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				Brain.cpp

INCLUDE1	=	Animal.hpp
INCLUDE2	=	Dog.hpp
INCLUDE3	=	Cat.hpp
INCLUDE4	=	Brain.hpp

all: $(BRAIN)

$(BRAIN)	: $(SRC) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) $(INCLUDE4)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(BRAIN)

clean		:
	rm -fr $(BRAIN)

re			: clean all
