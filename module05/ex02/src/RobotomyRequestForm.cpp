#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(cosnt std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm constructed\n";
}

/*: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.*/

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm::_signature(other._signature){
    std::cout << "RobotomyRequestForm copy contructor called!\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other){
        _signature = other._signature;
    }
    std::cout << "RobotomyRequestForm " << getName() << " assigned\n";
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm "<< getName() << " deleted\n";
}

const std::string& RobotomyRequestForm::getName(void) const{
    return (_target);
}

void RobotomyRequestForm::beSigned(const Bureaucrat &buro){
    if (this->_gradeSign < buro._grade){
        throw PermissionDenied();
    }
    this->_signature = true;
    std::cout << "bureaucrat " << buro.getName() <<" signed form " << this->getName() << "\n";
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {
    if (this->_gradeExec < buro._grade){
        throw PermissionDenied();
    }
    if (this->_serialNum % 2 == 0){
      std::cout << this->getName << " has been robotomized\n";
    }
    else{
      std::cout << "Unfortunatly, robotomy failed\n";
    }
    this->_serialNum++;
}
