ZOMBIE		=	Zombie

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp

INCLUDE		=	Zombie.hpp

all: $(ZOMBIE)

$(ZOMBIE)	:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(ZOMBIE)

clean		:
	rm -fr $(ZOMBIE)

re			: clean all
