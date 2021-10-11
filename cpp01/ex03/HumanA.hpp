#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
    std::string mName;
    Weapon& mWeapon;

    HumanA(std::string s, Weapon& w);
    void attack();
};

#endif