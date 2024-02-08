BTC			=	btc

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	main.cpp \
				BitcoinExchange.cpp

INCLUDES	=	BitcoinExchange.hpp

all: $(BTC)

$(BTC):	$(SRC) $(INCLUDES)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(BTC)

clean:
	rm -fr $(BTC)

fclean: clean

re: fclean all
