#include "Bureaucrat.hpp"


const std::string Bureaucrat::getName(void) const{
    return(_name);

}

int Bureaucrat::getGrade(void) const{
    return(_grade);
}

void Bureaucrat::incrGrade(void){
    _grade--;

}

void Bureaucrat::decrGrade(void){
    _grade++;

}

void Bureaucrat::GradeTooHighException(void){

}

void Bureaucrat::GradeTooLowException(void){

}

ostream& Bureaucrat::operator<<(ostream& os, const Bureaucrat& burocrat)
{
    os << burocrat._name << ", bureaucrat grade " << burocrat._grade << '.' << '\n';
    return os;
}