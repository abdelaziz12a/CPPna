

#include "Fixed.hpp"

Fixed::Fixed() {fixed_point = 0; std::cout << "Default constructor called" << std::endl;}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = other.getRawBits();

}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        fixed_point = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const 
{ 
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "getRawBits member function called" << std::endl;

    fixed_point = raw;
}


