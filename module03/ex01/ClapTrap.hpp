#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap{
    public:
        ClapTrap():;
        ClapTrap(std::string n):  Name(n), hitPoints(10), energyPoints(10), attackDamage(0) {};
        ClapTrap(ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName( void );
        int getHitPoints( void );
        int getEnergyPoints( void );
        int getAttackDamage( void );
        ~ClapTrap();
    protected:
        std::string Name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

};

#endif