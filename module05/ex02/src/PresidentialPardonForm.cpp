#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(cosnt std::string &target)
    : AForm("ShrubberyCreationForm", 25, 5), _target(target){
    std::cout << "PresidentialPardonForm constructed\n";
}
/*PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.*/

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm::_signature(other._signature){
    std::cout << "PresidentialPardonForm copy contructor called!\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other){
        _signature = other._signature;
    }
    std::cout << "PresidentialPardonForm " << getName() << " assigned\n";
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm "<< getName() << " deleted\n";
}

const std::string& PresidentialPardonForm::getName(void) const{
    return (_target);
}

void PresidentialPardonForm::beSigned(const Bureaucrat &buro){
    if (this->_gradeSign < buro._grade){
        throw PermissionDenied();
    }
    this->_signature = true;
    std::cout << "bureaucrat " << buro.getName() <<" signed form " << this->getName() << "\n";
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {
    if (this->_gradeExec < buro._grade){
        throw PermissionDenied();
    }
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
