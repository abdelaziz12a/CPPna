
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int     cont_contact;
        int     next_index;


    public:
        PhoneBook();
        void addContact();
        void searchContact();
        
};

#endif
