#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed"){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed (default)\n";
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap " << name << " copied\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(){
    std:: cout << "FragTrap " << name << " is deleted\n";
}

void FragTrap::highFivesGuys(void){
    std:: cout << "FragTrap " << name << " displays a positive high-fives request on the standard output\n";
}