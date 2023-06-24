/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:53:49 by synicole          #+#    #+#             */
/*   Updated: 2023/06/21 17:53:51 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

int main(void)
{
	// Initialize the phonebook with a maximum of 8 contacts
	PhoneBook phonebook(8);

	// Get the user input
	std::string input;
	do {
		std::cout << "Enter you command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			std::cout << "EXIT" << std::endl;
		else
			std::cout << "❌ Invalid command" << std::endl;
	} while (input != "EXIT" && !std::cin.eof());
	return (0);
}
