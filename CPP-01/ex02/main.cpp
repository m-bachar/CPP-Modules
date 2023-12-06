/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:17:06 by mbachar           #+#    #+#             */
/*   Updated: 2023/12/01 17:43:29 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET     "\x1b[0m"
#define RED       "\x1b[1;31m"
#define GREEN     "\x1b[1;32m"
#define ORANGE    "\x1b[1;34m"

int main()
{
    std::string str        = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << RED << "=============================================================\n" << RESET;
    std::cout << RESET << "The memory address of the string variable : " << GREEN << &str << std::endl;
    std::cout << RESET << "The memory address held by stringPTR      : " << GREEN << stringPTR << std::endl;
    std::cout << RESET << "The memory address held by stringREF      : " << GREEN << &stringREF << std::endl;
    std::cout << RED << "=============================================================\n" << RESET;
    std::cout << RESET << "The value of the string variable  : " << ORANGE << str << std::endl;
    std::cout << RESET << "The value pointed to by stringPTR : " << ORANGE << *stringPTR << std::endl;
    std::cout << RESET << "The value pointed to by stringREF : " << ORANGE << stringREF << std::endl;
    std::cout << RED << "=============================================================\n" << RESET;
}
