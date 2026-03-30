
#include "Zombie.hpp"

Zombie::Zombie() : name("UNOUN"){}

Zombie::~Zombie (){ std::cout << name << " is destroyed." << std::endl;}

void Zombie::setName(std::string nu){name = nu;}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}