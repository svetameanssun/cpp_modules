#include <iostream>
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main() {
    Intern intern;
    AForm* form;

    std::cout << "\n--- Valid forms ---\n";

    // 1. Shrubbery
    form = intern.makeForm("shrubbery creation", "Home");
    if (form)
        delete form;

    // 2. Robotomy
    form = intern.makeForm("robotomy request", "Bender");
    if (form)
        delete form;

    // 3. Presidential
    form = intern.makeForm("presidential pardon", "Alice");
    if (form)
        delete form;

    std::cout << "\n--- Invalid form ---\n";

    // 4. Invalid form
    form = intern.makeForm("coffee request", "Office");
    if (form)
        delete form;

    return 0;
}
