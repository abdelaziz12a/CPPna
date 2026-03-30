
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{ 

    FragTrap frag("FRAG-FREANDLY");

    frag.attack("bad_enemy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();
    frag.takeDamage(150);
    frag.attack("bad_enemy");

}