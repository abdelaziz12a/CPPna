#include "ClapTrap.hpp"



int main()
{
    ClapTrap clap("CLAP-888");

    clap.attack("target_1");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.takeDamage(20);
    clap.attack("target_2");
    clap.beRepaired(1);
}