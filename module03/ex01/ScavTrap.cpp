#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "--> ScavTrap " << name << " constructed!<--" << std::endl;
    std::cout << "This is a very similar, but different constructor message!\n";
}

ScavTrap::ScavTrap(const std::string& name)
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "--> ScavTrap " << name << " constructed!<--" << std::endl;
    std::cout << "This is a very similar, but different constructor message!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : name(other.name), hitPoints(other.hitPoints),
      energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ScavTrap " << name << " copied!" << std::endl;
}

ScavTrap::ScavTrap::operator=(const ScavTrap& other) {
    if(this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap " << name << " assigned!" << std::endl;
    return *this;
}



void ScavTrap::attack(const std::string& target) {
    if(hitPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack: no hit points left!" << std::endl;
        return;
    }
    if(energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack: no energy left!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}



