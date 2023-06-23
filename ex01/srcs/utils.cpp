/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:13:05 by synicole          #+#    #+#             */
/*   Updated: 2023/06/23 10:13:06 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

/**
 * Check if a string contains only digits
 * @param str
 * @return true if the string contains only digits, false otherwise
 */
bool containsOnlyDigit(std::string str) {
	for (int i = 0; i < (int)str.length(); i++) {
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

/**
 * Format a string to a fixed length of 10 characters
 * @param str
 * @return the formatted string
 */
std::string formatString(std::string str) {
	std::string formattedString;

	// If the string is longer than 10 characters, we truncate it and add a dot
	// at the end
	if (str.length() > 10) {
		formattedString = str.substr(0, 9);
		formattedString.append(".");
	}
	// If the string is shorter than 10 characters, we add spaces at the
	// beginning
	else {
		formattedString = str;
		for (int i = 0; i < 10 - (int)str.length(); i++) {
			formattedString.insert(0, " ");
		}
	}
	return (formattedString);
}
