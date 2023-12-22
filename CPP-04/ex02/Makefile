BRAIN		=	Brain

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				Brain.cpp

INCLUDE1	=	Animal.hpp
INCLUDE2	=	Dog.hpp
INCLUDE3	=	Cat.hpp
INCLUDE4	=	WrongAnimal.hpp
INCLUDE5	=	WrongCat.hpp
INCLUDE6	=	Brain.hpp

all: $(BRAIN)

$(BRAIN)	: $(SRC) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) $(INCLUDE4) $(INCLUDE5) $(INCLUDE6)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(BRAIN)

clean		:
	rm -fr $(BRAIN)

re			: clean all
