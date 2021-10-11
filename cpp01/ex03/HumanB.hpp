#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
    std::string mName;
    Weapon* mWeapon;

    HumanB(std::string s);
    void attack();
    void setWeapon(Weapon& type);
};

#endif