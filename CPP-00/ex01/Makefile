PHONEBOOK	=	phonebook

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp

INCLUDE1	=	PhoneBook.hpp

INCLUDE2	=	Contact.hpp

all: $(PHONEBOOK)

$(PHONEBOOK) : $(INCLUDE1) $(INCLUDE2) $(SRC)
	$(CPP) $(CPPFLAGS) $(SRC) -o $(PHONEBOOK)

clean		:
	rm -fr $(PHONEBOOK)

re			: clean all
