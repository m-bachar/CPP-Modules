# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 20:29:22 by mbachar           #+#    #+#              #
#    Updated: 2023/09/19 02:37:22 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHONEBOOK	=	phonebook

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address

SRC			=	phonebook.cpp

INCLUDE		=	phonebook.hpp

all: $(PHONEBOOK)

$(PHONEBOOK) :
	$(CPP) $(CPPFLAGS) $(SRC) -o $(PHONEBOOK)

clean		:
	rm -fr $(PHONEBOOK)

re			: clean all