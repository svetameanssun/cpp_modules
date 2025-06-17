#pragma once
#include <iostream>
#include <string>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(const std::string& weaponType) : type(weaponType) {};
        Weapon(): type("unarmed") {};

        const std::string &getType() const;
        void setType(const std::string& newType);
};




