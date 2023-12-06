HARL		=	Harl

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				Harl.cpp

all: $(HARL)

$(HARL)	:
	$(CPP) $(CPPFLAGS) $(SRC) -o $(HARL)

clean		:
	rm -fr $(HARL)

re			: clean all
