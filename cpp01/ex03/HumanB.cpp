
#include "HumanB.hpp"

HumanB::HumanB(std::string n): name(n), MyW(NULL){}

void HumanB::attack() const
{
    if (MyW)
        std::cout << name << " attacks with their " << MyW->getType() << std::endl ;
    else
        std::cout << name << " has no weapon " << std::endl ;

}

void HumanB::setWeapon(Weapon &w)
{
    MyW = &w;
}