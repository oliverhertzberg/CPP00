/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:35:47 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 18:15:38 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp" 

// constructor
Contact::Contact(){
    this->empty = 0;
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

// deconstructor
Contact::~Contact(){
}

// methods
void    Contact::add_first_name(const std::string& first_name){
    this->first_name = first_name;
}

void    Contact::add_last_name(const std::string& last_name){
    this->last_name = last_name;
}

void    Contact::add_nickname(const std::string& nickname){
    this->nickname = nickname;
}

void    Contact::add_phone_number(const std::string& phone_number){
    this->phone_number = phone_number;
}

void    Contact::add_darkest_secret(const std::string& darkest_secret){
            this->darkest_secret = darkest_secret;
}
