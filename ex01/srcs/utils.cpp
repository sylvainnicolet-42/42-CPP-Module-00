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

bool containsOnlyDigit(std::string str) {
	for (int i = 0; i < (int)str.length(); i++) {
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string formatString(std::string str) {
	std::string formattedString;

	if (str.length() > 10) {
		formattedString = str.substr(0, 9);
		formattedString.append(".");
	}
	else {
		formattedString = str;
		for (int i = 0; i < 10 - (int)str.length(); i++) {
			formattedString.insert(0, " ");
		}
	}
	return (formattedString);
}
