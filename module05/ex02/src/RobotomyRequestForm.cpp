#include "../include/RobotomyRequestForm.hpp"

int RobotomyRequestForm::_serialNum = 0;

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm constructed\n";
}

/*: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.*/


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm copy contructor called!\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other){
        this->setSignature(other.getSignature());
    }
    std::cout << "RobotomyRequestForm " << getName() << " assigned\n";
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm "<< getName() << " deleted\n";
}

const std::string& RobotomyRequestForm::getTarget(void) const{
    return (_target);
}

void RobotomyRequestForm::beSigned(const Bureaucrat &buro){
    if (this->getGradeSign() < buro.getGrade()){
        throw PermissionDenied();
    }
    this->setSignature(true);
}

int RobotomyRequestForm::getSerialNum(void) const{
    return (this->_serialNum); 
}

void RobotomyRequestForm::incrSerialNum(void){
    this->_serialNum++;
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) {
    if (this->getGradeExec() < executor.getGrade()){
        throw PermissionDenied();
    }
    if (this->getSerialNum() % 2 == 0){
      std::cout << this->getName() << " has been robotomized\n";
    }
    else{
      std::cout << "Unfortunatly, robotomy failed\n";
    }
    this->incrSerialNum();
}
