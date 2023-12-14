FIXED		=	Fixed

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Fixed.cpp

INCLUDE		=	Fixed.hpp

all: $(FIXED)

$(FIXED)	: $(SRC) $(INCLUDE)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(FIXED)

clean		:
	rm -fr $(FIXED)

re			: clean all
