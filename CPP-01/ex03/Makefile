WEAPON		=	Weapon

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp

all: $(WEAPON)

$(WEAPON)	:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(WEAPON)

clean		:
	rm -fr $(WEAPON)

re			: clean all
