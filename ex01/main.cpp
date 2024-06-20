/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:22:36 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 18:39:45 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string ft_substr(std::string str){
    if (str.length() > 9)
    {
        str = str.substr(0, 9);
        str = str + ".";
    }
    else
        str = str.substr(0, 10);
    return (str);
}

void    print_instructions(){
    std::cout << std::setw(40) << std::setfill('-') << ""
              << std::setfill(' ') << std::endl
              << "| " << "Enter 'ADD' to add a new contact" << "       |" << std::endl
              << "| " << "Enter 'SEARCH' to search for a contact" << " |" << std::endl
              << "| " << "Enter 'EXIT' to exit the program" << "       |" << std::endl
              << std::setw(40) << std::setfill('-') << ""
              << std::setfill(' ') << "\n" << std::endl;
}

void    add_contact(PhoneBook* phonebook){
    class Contact contact;
    std::string input;

    std::cout << "\nEnter first name: ";
    std::getline(std::cin, input);
    contact.add_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.add_last_name(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.add_nickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.add_phone_number(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.add_darkest_secret(input);

    phonebook->add_contact(contact);
    std::cout << "\nContact created!\n\n" << std::endl;
}

void    search_contact(PhoneBook* phonebook){
    std::string input;

    if (!phonebook->display_contacts())
        return ;
    std::cout << "Enter id of contact to display: ";
    std::getline(std::cin, input);
    std::cout << std::endl;
    while (input.length() > 1 || stoi(input) > 7 || stoi(input) < 0)
    {
        std::cout << "Our amazing PhoneBook™ can store up to 8 contacts" << std::endl;
        std::cout << "Please enter an index between 0 and 7" << "\n" << std::endl;
        std::cout << "Enter id of contact to display: ";
        std::getline(std::cin, input);
    }
    if (!phonebook->display_contact(stoi(input)))
        search_contact(phonebook);
}

int main(int argc, char **argv){
    PhoneBook phonebook;
    std::string  input;

    std::cout << "---------------------------------" << std::endl 
              << "| The Awesome PhoneBook Program |\n"
              << "---------------------------------" << std::endl;
    print_instructions();
    while (1) 
    {
        std::getline(std::cin, input);
        if (!input.compare("ADD"))
            add_contact(&phonebook);
        else if (!input.compare("SEARCH"))
            search_contact(&phonebook);
        else if (!input.compare("EXIT"))
            exit(0);
        else
            std::cout << "Invalid input!\n";
        print_instructions();
    }
}
