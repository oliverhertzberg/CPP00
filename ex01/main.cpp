// #include "Contact.hpp"
// #include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <ios>
#include <limits>

class   PhoneBook
{
    private:
        Contact*  contacts[8];
    public:
        int num_of_contacts = 0;
    void    add_contact(Contact* contact)
    {
        if (num_of_contacts + 1 > 8)
            num_of_contacts = 0;
        this->contacts[num_of_contacts] = contact;
        num_of_contacts++;
    }
    
};

class   Contact
{
    public:
        char    *first_name;
        char    *last_name;
        char    *nickname;
        char    *phone_number;
        char    *darkest_secret;
    
};

void    print_instructions()
{
    std::cout << "Enter 'ADD' to add a new contact\n";
    std::cout << "Enter 'SEARCH' to search for a contact\n";
    std::cout << "Enter 'EXIT' to exit the program\n";
}

void    add_contact(PhoneBook* phonebook)
{
    
}

void    search_contact(PhoneBook* phonebook)
{

}

int main(int argc, char **argv)
{
    PhoneBook phonebook;
    std::string  input;

    std::cout << "The Awesome PhoneBook Program\n";
    print_instructions();
    while (1)
    {
        std::cin >> input;
        if (!std::strcmp(input.c_str(), "ADD"))
            add_contact(&phonebook);
        else if (!std::strcmp(input.c_str(), "SEARCH"))
            search_contact(&phonebook);
        else if (!std::strcmp(input.c_str(), "EXIT"))
            exit(0);
        else
        {
            std::cout << "Invalid input:\n";
            print_instructions();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}