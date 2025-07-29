#include "Common.hpp"

const char * Bureaucrat::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!\n");
}

const char *Bureaucrat::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!\n");
}

const char *Form::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!\n");
}

const char *Form::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!\n");
}
