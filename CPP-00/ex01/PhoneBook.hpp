/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:29:19 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/17 21:28:09 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
public:
	Contact		contacts[8];
};

void	add_contact(PhoneBook &book, int i);
void	search_contact(PhoneBook &book, int reference);

#endif