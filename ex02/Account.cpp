/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:13:22 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 19:57:58 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

    // static int	_nbAccounts;
	// static int	_totalAmount;
	// static int	_totalNbDeposits;
	// static int	_totalNbWithdrawals;

	// int				_accountIndex;
	// int				_amount;
	// int				_nbDeposits;
	// int				_nbWithdrawals;


// constructor
Account::Account( int initial_deposit ){
    _nbAccounts = 0;
    _totalAmount = initial_deposit;
    _totalNbDeposits = 1;
    _totalNbWithdrawals = 0;
}

// alternate constructor
Account::Account( void ){
    _nbAccounts = 1;
    _totalAmount = 0;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
}

// deconstructor
Account::~Account(){
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
    return ;
}

// static private method
void    Account::_displayTimestamp( void ){
    
}

// non-static methods
void    Account::makeDeposit( int deposit){
    
}

bool    Account::makeWithdrawal( int withdrawal ){
    
}

int     Account::checkAmount( void ) const{
    
}

void    Account::displayStatus( void ) const{
    
}