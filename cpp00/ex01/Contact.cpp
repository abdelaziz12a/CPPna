
#include "Contact.hpp"

void Contact::setFirstName(std::string fn){firstName = fn;}

void Contact::setLastName(std::string ln){lastName = ln;}

void Contact::setNickname(std::string nk){nickName = nk;}

void Contact::setPhoneNumber(std::string pn){phoneNumber = pn;}

void Contact::setDarkestSecret(std::string ds){darkestSecret = ds;}

void Contact::setContact(std::string fn,std::string ln,std::string nk,std::string pn,std::string ds)
{
    setFirstName(fn);
    setLastName(ln);
    setNickname(nk);
    setPhoneNumber(pn);
    setDarkestSecret(ds);
}

std::string Contact::getFirstName() const{return firstName;}

std::string Contact::getLastName() const{return lastName;}

std::string Contact::getNickname() const{return nickName;}

std::string Contact::getPhoneNumber() const{return phoneNumber;}

std::string Contact::getDarkestSecret() const{return darkestSecret;}