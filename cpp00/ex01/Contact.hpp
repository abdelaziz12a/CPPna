
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string darkestSecret;
        std::string phoneNumber;
    public:
        void setContact(std::string fn,std::string ln,std::string nk,std::string pn,std::string ds);
        void setFirstName(std::string fn);
        void setLastName(std::string ln);
        void setNickname(std::string nk);
        void setPhoneNumber(std::string pn);
        void setDarkestSecret(std::string ds);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
