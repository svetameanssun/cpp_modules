#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


Intern::Intern(){
    std::cout << "Intern created\n";
}

Intern::Intern(const Intern &other){
    (void)other; 

}

Intern &Intern::operator=(const Intern &other){
    (void)other;
    return (*this);
}

Intern::~Intern(){
    std::cout << "Intern destroyed\n";
}

typedef AForm *(*FormCreator)(const std::string& target);

AForm *createRobotomyForm(const std::string &target){
    return new RobotomyRequestForm(target);

}

AForm *createShrubberyForm(const std::string &target){
    return new ShrubberyCreationForm(target);
}

AForm *createPardonForm(const std::string &target){
    return new PresidentialPardonForm(target);
}



AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) {
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[] = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPardonForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](formTarget);
        }
    }

    std::cerr << "Intern couldn't find form with name: " << formName << std::endl;
    return NULL;
}