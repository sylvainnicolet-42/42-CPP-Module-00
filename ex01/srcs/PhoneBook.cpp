/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:00:18 by synicole          #+#    #+#             */
/*   Updated: 2023/06/21 18:00:19 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _maxContacts(8), _nbContacts(0) { }

PhoneBook::PhoneBook(int maxContacts) : _maxContacts(maxContacts), _nbContacts(0) { }

PhoneBook::~PhoneBook(void) {
	std::cout << "📔 PhoneBook is closed, all contact will be lost! 😪" << std::endl;
}

void	PhoneBook::addContact(void) {
	Contact contact;

	std::cout << "📝 Add contact" << std::endl;
	std::string input;

	do {
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ First name cannot be empty!" << std::endl;
		else
			contact.setFirstName(input);
	} while (input.empty());

	do {
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ Last name cannot be empty!" << std::endl;
		else
			contact.setLastName(input);
	} while (input.empty());

	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ Nickname cannot be empty!" << std::endl;
		else
			contact.setNickname(input);
	} while (input.empty());

	do {
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ Phone number cannot be empty!" << std::endl;
		else
			contact.setPhoneNumber(input);
	} while (input.empty());

	do {
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ Darkest secret cannot be empty!" << std::endl;
		else
			contact.setDarkestSecret(input);
	} while (input.empty());

	// Add the contact to the phonebook
	if (this->_nbContacts == this->_maxContacts) {
		std::cout << "⚠️ PhoneBook is full, contact will replace the oldest one!" << std::endl;

		// Shift the contacts to the left and replace the last one with the new contact
		for (int i = 0; i < this->_maxContacts; i++) {
			if (i == this->_maxContacts - 1)
				this->_contacts[i] = contact;
			else
				this->_contacts[i] = this->_contacts[i + 1];
		}
	}
	else
	{
		this->_contacts[this->_nbContacts] = contact;
		this->_nbContacts++;
	}
	std::cout << "✅ Contact added!" << std::endl;
	std::cout << "📔 PhoneBook (" << this->_nbContacts << "/" << this->_maxContacts << ")" << std::endl;
}

void	PhoneBook::searchContact(void) const {

	// Display the contacts
	std::cout << "📔 Contacts" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_nbContacts; i++) {
		std::cout << "|" << formatString(std::to_string(i)) << "|";
		std::cout << formatString(this->_contacts[i].getFirstName()) << "|";
		std::cout << formatString(this->_contacts[i].getLastName()) << "|";
		std::cout << formatString(this->_contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}

	// Ask for the index of the contact to display
	displayContactByIndex();
}

void PhoneBook::displayContactByIndex(void) const {
	std::cout << "🔍 Find contact" << std::endl;
	std::string input;

	do {
		std::cout << "Index (q to quite): ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "⚠️ Index cannot be empty!" << std::endl;
		else if (containsOnlyDigit(input))
		{
			int index = std::stoi(input);
			if (index < 0 || index >= this->_nbContacts) {
				std::cout << "❌ Error: index out of range" << std::endl;
			}
			else {
				std::cout << "✅ Contact found!" << std::endl;
				std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
				std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
				std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
				std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
			}
		}
		else if (input != "q")
			std::cout << "❌ Error: index must be a number" << std::endl;
	} while (input != "q");
}
