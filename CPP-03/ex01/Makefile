CLAPTRAP	=	ClapTrap

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp

INCLUDE1	=	ClapTrap.hpp

INCLUDE2	=	ScavTrap.hpp

all: $(CLAPTRAP)

$(CLAPTRAP)	: $(SRC) $(INCLUDE1) $(INCLUDE2)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(CLAPTRAP)

clean		:
	rm -fr $(CLAPTRAP)

re			: clean all
