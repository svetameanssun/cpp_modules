#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->Name = "Unnamed";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap --Unnamed-- created\n";
}

Claptrap::ClapTrap(std::string n){
    this->Name = n
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap --"<< this->Name <<"-- created\n";
}

void ClapTrap::attack(const std::string& target){
    if (this->hitPoints <= 0)
    {
        std::cout << "I cannot do anything, I am dead!\n";
        return ;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "I cannot do anything, I have no energy!\n";
        return ;
    }
    std::cout << "the target --"<< target << "-- lost "
    << this->attackDamage << " hitPoints." <<"\n";
    this->energyPoints--;

}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints <= 0)
    {
        std::cout << "I am already dead, stop hitting me!\n";
        return ;
    }
    this->hitPoints -= (amount);
    std::cout << this->Name << " lost " << amount << " hit points.\n"
        << "       Current hit points = " << this->hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hitPoints <= 0)
    {
        std::cout << "I cannot do anything, I am dead!\n";
        return ;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "I cannot do anything, I have no energy!\n";
        return ;
    }
    std::cout << this->Name << " got " << amount << "hit points.\n"
        << "and lost 1 energy point.\n"
        << "       Current hit points = " << this->hitPoints << "\n"
        << "       Current energy points = " << this->hitPoints << "\n";
    this->hitPoints += (amount);
    this->energyPoints--;
}


std::string ClapTrap::getName( void ){
    return (this->Name);
}

int ClapTrap::getHitPoints( void ){
    return (this->hitPoints);
}

int ClapTrap::getEnergyPoints( void ){
    return (this->energyPoints);
}

int ClapTrap::getAttackDamage( void ){
    return (this->attackDamage);
}

ClapTrap::~ClapTrap(){
    std::cout << this->Name << " removed\n";
}