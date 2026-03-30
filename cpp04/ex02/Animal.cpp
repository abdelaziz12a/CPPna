
#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal&other)
{
    std::cout << "Animal copy assignment called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}


std::string Animal::getType() const {return type;}

Animal::~Animal()
{
     std::cout << "Animal destructor called" << std::endl;
}