/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:16:27 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/06/22 18:06:27 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <string_view>
#include <limits>

std::string ft_substr(std::string str);

class   Contact{
    private:
        int         empty;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
   
    public:
        // constructor
        Contact();
    
        // deconstructor
        ~Contact();

    // methods
    void    add_first_name(const std::string& first_name);
    void    add_last_name(const std::string& last_name);
    void    add_nickname(const std::string& nickname);
    void    add_phone_number(const std::string& phone_number);
    void    add_darkest_secret(const std::string& darkest_secret);

    // getters
    const std::string getFirstName();
    const std::string getLastName();
    const std::string getNickname();
    const std::string getPhoneNumber();
    const std::string getDarkestSecret();
    const int         getEmpty();

    // setter
    void            setEmpty(const int i);
    
};

#endif
