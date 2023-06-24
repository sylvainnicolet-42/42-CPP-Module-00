/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:57:19 by synicole          #+#    #+#             */
/*   Updated: 2023/06/24 15:57:20 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

/**
 * Constructor
 * @param initial_deposit
 */
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts) ,_amount(initial_deposit) ,_nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

/**
 * Destructor
 */
Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return true;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
 * Print current time using the format [19920104_091532]
 */
void Account::_displayTimestamp(void) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year;
	if (1 + ltm->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + ltm->tm_mon;
	if (ltm->tm_mday < 10)
		std::cout << "0";
	std::cout << ltm->tm_mday << "_";
	if (ltm->tm_hour < 10)
		std::cout << "0";
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0";
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0";
	std::cout << ltm->tm_sec << "] ";
}

// Static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
