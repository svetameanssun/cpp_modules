#include "Common.hpp"

const char * Bureaucrat::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!");
}

const char *Form::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!");
}
