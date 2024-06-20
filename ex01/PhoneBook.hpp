/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:17:29 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/20 18:16:38 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"

class   PhoneBook
{
    private:
        Contact contacts[8];
        int     num_of_contacts;

    public:
        // constructor
        PhoneBook();
        
        // deconstructor
        ~PhoneBook();
        
        // methods
        void    add_contact(Contact contact);
        int     display_contacts();
        int     display_contact(int index);
};

#endif