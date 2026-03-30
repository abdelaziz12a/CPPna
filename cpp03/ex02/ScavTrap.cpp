
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    Name = "X";
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " is ready" << std::endl;
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if(this != &other)
    {
       ClapTrap::operator=(other);
    }
       
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << Name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points--;
        std::cout << "ScavTrap " << Name << " attacks " << target;
        std::cout << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << Name << " cannot attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}