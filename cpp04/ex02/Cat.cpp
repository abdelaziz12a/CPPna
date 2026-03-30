#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat&other) 
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
        Animal::operator=(other);
    }
    return *this;
}
void Cat::makeSound() const
{
     std::cout << "mee-OW !" << std::endl;
}

Cat::~Cat()
{
    delete brain;
     std::cout << "Cat destructor called" << std::endl;
}