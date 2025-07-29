#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(){
    return ("Grade is too high!\n");
}

const char *Bureaucrat::GradeTooLowException::what(){
    return ("Grade is low!\n");
}