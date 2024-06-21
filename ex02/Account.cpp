/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:13:22 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/21 13:07:06 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// initializing static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account( int initial_deposit ){
    _displayTimestamp();
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

// alternate constructor
Account::Account( void ){
}

// deconstructor
Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}


// static pubic methods
int     Account::getNbAccounts( void ){
    return(_nbAccounts);
}

int     Account::getTotalAmount( void ){
    return (_totalAmount);
}

int	    Account::getNbDeposits( void ){
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

// static private method
void    Account::_displayTimestamp( void ){
    std::time_t now = std::time(nullptr);
    std::tm *timeinfo = std::localtime(&now);

    std::cout << "["
              << std::setw(4) << std::setfill('0') << (timeinfo->tm_year + 1900) // year
              << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)     // month
              << std::setw(2) << std::setfill('0') << timeinfo->tm_mday          // day
              << "_"
              << std::setw(2) << std::setfill('0') << timeinfo->tm_hour          // hour
              << std::setw(2) << std::setfill('0') << timeinfo->tm_min           // minute
              << std::setw(2) << std::setfill('0') << timeinfo->tm_sec           // second
              << "] ";
}   

// non-static methods
void    Account::makeDeposit( int deposit ){
    _displayTimestamp();
    _totalAmount += deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";
              if (withdrawal > this->_amount){
                std::cout << "refused" << std::endl;
                return (false);
              }
    this->_amount -= withdrawal;
    std::cout << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals + 1
              << std::endl;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return (true);
}

int     Account::checkAmount( void ) const{
    return (0);
}

void    Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
