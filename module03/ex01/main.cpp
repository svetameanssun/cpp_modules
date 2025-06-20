#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===\n";
    ScavTrap s1("Serena");

    std::cout << "\n=== Performing actions ===\n";
    s1.attack("Bandit");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();

    std::cout << "\n=== Copy test ===\n";
    ScavTrap s2 = s1;

    std::cout << "\n=== End of main ===\n";
    return 0;
}
