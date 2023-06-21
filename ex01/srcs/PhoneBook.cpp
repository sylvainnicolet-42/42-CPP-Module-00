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

# include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called" << std::endl;
}
