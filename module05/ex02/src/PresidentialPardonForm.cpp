#include "../include/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 25, 5), _target(target){
    std::cout << "PresidentialPardonForm constructed\n";
}
/*PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.*/

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy contructor called!\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other){
        this->setSignature(other.getSignature());
    }
    std::cout << "PresidentialPardonForm " << getName() << " assigned\n";
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm "<< getName() << " deleted\n";
}

const std::string& PresidentialPardonForm::getTarget(void) const{
    return (_target);
}

void PresidentialPardonForm::beSigned(const Bureaucrat &buro){
    if (this->getGradeSign() < buro.getGrade()){
        throw PermissionDenied();
    }
    this->setSignature(true);
    std::cout << "bureaucrat " << buro.getName() <<" signed form " << this->getName() << "\n";
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {
    if (this->getGradeExec() < executor.getGrade()){
        throw PermissionDenied();
    }
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
