FRAGTRAP	=	FragTrap

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp

INCLUDE1	=	ClapTrap.hpp

INCLUDE2	=	ScavTrap.hpp

INCLUDE3	=	FragTrap.hpp

all: $(FRAGTRAP)

$(FRAGTRAP)	: $(SRC) $(INCLUDE1) $(INCLUDE2)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(FRAGTRAP)

clean		:
	rm -fr $(FRAGTRAP)

re			: clean all
