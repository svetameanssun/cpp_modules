#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Bender");

    robot.attack("a box");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10); // should "die"
    robot.attack("a crate"); // should not work
    robot.beRepaired(5);     // should not work

    return 0;
}
