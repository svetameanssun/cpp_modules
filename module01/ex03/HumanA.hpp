#pragma once
#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon &weaponA;
    public:
        HumanA(std::string name, Weapon& weaponType): name(name), weaponA(weaponType){};
        void attack();
};