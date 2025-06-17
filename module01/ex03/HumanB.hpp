#pragma once
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon *weaponB;
    public:
        HumanB(std::string name): name(name), weaponB(NULL){};
        void attack();
        void setWeapon(Weapon &weaponType);
};