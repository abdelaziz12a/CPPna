
#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w): name(n), MyW(w){}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << MyW.getType() << std::endl ;
}

