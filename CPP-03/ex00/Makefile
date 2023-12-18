CLAPTRAP	=	ClapTrap

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ClapTrap.cpp

INCLUDE		=	ClapTrap.hpp

all: $(CLAPTRAP)

$(CLAPTRAP)	: $(SRC) $(INCLUDE)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(CLAPTRAP)

clean		:
	rm -fr $(CLAPTRAP)

re			: clean all
