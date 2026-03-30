
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ClapTrap
{
    protected:
        std::string Name;
        unsigned int Hit_points;
        unsigned int Energy_points;
        unsigned int Attack_damage;

    public:

        ClapTrap();
        ClapTrap(std::string name);
        
        ClapTrap(const ClapTrap& other);               
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ~ClapTrap();
};


class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string name);

        ScavTrap(const ScavTrap& other);   
        ScavTrap& operator=(const ScavTrap& other); 

        void attack(const std::string& target);
        void guardGate();
        ~ScavTrap();
};

#endif