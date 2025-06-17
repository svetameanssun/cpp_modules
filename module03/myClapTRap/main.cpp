#include "ClapTrap.hpp"

int main(){
    ClapTrap robot01("robot");
    std::string target = "a box";

    robot01.attack(target);
    std::cout << robot01.getName() << " has " << robot01.getHitPoints() << " hit points" << "\n";
    
    robot01.takeDamage(5);
    robot01.takeDamage(10);

    robot01.beRepaired(1);
    robot01.attack(target);
    robot01.takeDamage(5);
}