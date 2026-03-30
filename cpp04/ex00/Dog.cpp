#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog&other) 
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}
void Dog::makeSound() const
{
    std::cout << "woof woof grrr... !" << std::endl;
}

Dog::~Dog()
{
     std::cout << "Dog destructor called" << std::endl;
}