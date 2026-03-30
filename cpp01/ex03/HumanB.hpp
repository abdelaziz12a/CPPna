#ifndef HUMANB_HPP 
#define HUMANB_HPP

 #include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *MyW;
    public:
        HumanB(std::string n);
        void attack() const;
        void setWeapon(Weapon &w);

};

#endif