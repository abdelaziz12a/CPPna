
#include "Zombie.hpp"

int main()
{
    
    Zombie *z1 = newZombie("gon");
    z1->announce();
    randomChump("gin");
    delete z1;
}

