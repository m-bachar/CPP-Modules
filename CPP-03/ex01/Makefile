SCAVTRAP	=	ScavTrap

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp

INCLUDE1	=	ClapTrap.hpp

INCLUDE2	=	ScavTrap.hpp

all: $(SCAVTRAP)

$(SCAVTRAP)	: $(SRC) $(INCLUDE1) $(INCLUDE2)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(SCAVTRAP)

clean		:
	rm -fr $(SCAVTRAP)

re			: clean all
