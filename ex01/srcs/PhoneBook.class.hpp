/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:55:10 by synicole          #+#    #+#             */
/*   Updated: 2023/06/21 17:55:12 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include "Contact.class.hpp"
#include "utils.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		PhoneBook(int maxContacts);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void) const;
		void 	displayContactByIndex(void) const;
	private:
		Contact	_contacts[8];
		int		_maxContacts;
		int		_nbContacts;
};

#endif
