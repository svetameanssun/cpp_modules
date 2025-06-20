#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap claptrap("Clapy");
    ScavTrap scavtrap("Scavy");
    FragTrap fragtrap("Fragy");

    claptrap.attack("Scavy");
    scavtrap.takeDamage(10);
    scavtrap.guardGate();
    scavtrap.attack("Fragy");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(15);
    fragtrap.attack("Scavy");
    scavtrap.takeDamage(30);
    fragtrap.highFivesGuys();
    return (0);
}
