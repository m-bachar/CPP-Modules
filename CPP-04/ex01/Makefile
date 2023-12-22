ANIMAL		=	Animal

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

INCLUDE1	=	Animal.hpp
INCLUDE2	=	Dog.hpp
INCLUDE3	=	Cat.hpp
INCLUDE4	=	WrongAnimal.hpp
INCLUDE5	=	WrongCat.hpp

all: $(ANIMAL)

$(ANIMAL)	: $(SRC) $(INCLUDE1) $(INCLUDE2) $(INCLUDE3) $(INCLUDE4) $(INCLUDE5)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(ANIMAL)

clean		:
	rm -fr $(ANIMAL)

re			: clean all
