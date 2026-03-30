
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{ 
    ScavTrap scav("SCAV-Solder-1");

    scav.attack("enemy_1");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();
    scav.takeDamage(100);
    scav.attack("enemy");
}