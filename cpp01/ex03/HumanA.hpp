#ifndef HUMANA_HPP 
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &MyW;
    public:
        HumanA(std::string n, Weapon &w);
        void attack() const;

};

#endif