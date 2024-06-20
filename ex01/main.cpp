/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:22:36 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 14:54:01 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Contact.hpp"
// #include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <string_view>
#include <limits>

class   Contact
{
    public:
        int empty;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        Contact(){
            this->empty = 0;
            this->first_name = "";
            this->last_name = "";
            this->nickname = "";
            this->phone_number = "";
            this->darkest_secret = "";
        }
        void    add_first_name(const std::string& first_name){
            this->first_name = first_name;
        }
        void    add_last_name(const std::string& last_name){
            this->last_name = last_name;
        }
        void    add_nickname(const std::string& nickname){
            this->nickname = nickname;
        }
        void    add_phone_number(const std::string& phone_number){
            this->phone_number = phone_number;
        }
        void    add_darkest_secret(const std::string& darkest_secret){
            this->darkest_secret = darkest_secret;
        }
};

std::string ft_substr(std::string str)
{
    if (str.length() > 9)
    {
        str = str.substr(0, 9);
        str = str + ".";
    }
    else
        str = str.substr(0, 10);
    return (str);
}

class   PhoneBook
{
    private:
        Contact contacts[8];

    public:
        int num_of_contacts;
    
    PhoneBook() {
        num_of_contacts = 0;
        for (int i = 0; i < 8; i++){
        contacts[i].empty = 1;
        }
    }

    void    add_contact(Contact contact){
        if (num_of_contacts + 1 > 8)
            num_of_contacts = 0;
        this->contacts[num_of_contacts] = contact;
        num_of_contacts++;
    }
    int    display_contacts() {
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
    int    display_contact(int index){
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

};

void    print_instructions()
{
    std::cout << std::setw(40) << std::setfill('-') << ""
              << std::setfill(' ') << std::endl
              << "| " << "Enter 'ADD' to add a new contact" << "       |" << std::endl
              << "| " << "Enter 'SEARCH' to search for a contact" << " |" << std::endl
              << "| " << "Enter 'EXIT' to exit the program" << "       |" << std::endl
              << std::setw(40) << std::setfill('-') << ""
              << std::setfill(' ') << "\n" << std::endl;
}

void    add_contact(PhoneBook* phonebook)
{
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

void    search_contact(PhoneBook* phonebook)
{
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

int main(int argc, char **argv)
{
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