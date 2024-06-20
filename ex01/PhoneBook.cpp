/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:22:57 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 18:15:52 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook() {
    num_of_contacts = 0;
    for (int i = 0; i < 8; i++){
    contacts[i].empty = 1;
    }
}

// deconstructor
PhoneBook::~PhoneBook(){
}

// methods
void    PhoneBook::add_contact(Contact contact){
    if (num_of_contacts + 1 > 8)
        num_of_contacts = 0;
    this->contacts[num_of_contacts] = contact;
    num_of_contacts++;
}

int    PhoneBook::display_contacts() {
    if (contacts[0].empty == 1){
        std::cout << "PhoneBook is empty!\n" << std::endl;
        return 0;
    }
    std::cout << "\nContacts:\n" << std::endl;

    // printing the headers:
    std::cout << std::setw(10) << "index"
              << " | " << std::setw(10) << "first name"
              << " | " << std::setw(10) << "last name"
              << " | " << std::setw(10) << "nickname"
              << std::endl;
        
    // printing a separator line:
    std::cout << std::setw(10) << std::setfill('-') << ""
              << " | " << std::setw(10) << std::setfill('-') << ""
              << " | " << std::setw(10) << std::setfill('-') << ""
              << " | " << std::setw(10) << std::setfill('-') << ""
              << std::setfill(' ') << std::endl;

    // printing contacts:
    for (int i = 0; i < 8; i++){
        if (contacts[i].empty != 1)
        {
            std::cout << std::setw(10) << i
                      << " | " << std::setw(10) << ft_substr(contacts[i].first_name)
                      << " | " << std::setw(10) << ft_substr(contacts[i].last_name)
                      << " | " << std::setw(10) << ft_substr(contacts[i].nickname)
                      << "\n"
                      << std::endl;
        }
    }
    return (1);
}

int    PhoneBook::display_contact(int index){
    if (contacts[index].empty == 1){
        std::cout << "Contact doesn't exist!" << std::endl;
        return (0);
    }
    else{
        std::cout << "--------------------------------------------------------" << std::endl
                  << "First Name: " << contacts[index].first_name << std::endl
                  << "Last Name: " << contacts[index].last_name << std::endl
                  << "Nickname: " << contacts[index].nickname << std::endl
                  << "Phone Number: " << contacts[index].phone_number << std::endl
                  << "Darkest Secret: " << contacts[index].darkest_secret << std::endl
                  << "--------------------------------------------------------" << std::endl
                  << std::setfill('-') << ""
                  << std::setfill(' ') << std::endl;
    }
    return (1);
}
