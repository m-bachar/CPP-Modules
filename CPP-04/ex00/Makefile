ANIMAL		=	Animal

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp

INCLUDE1	=	Animal.hpp
INCLUDE2	=	Dog.hpp
INCLUDE3	=	Cat.hpp

all: $(ANIMAL)

$(ANIMAL)	: $(SRC) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(ANIMAL)

clean		:
	rm -fr $(ANIMAL)

re			: clean all
