#include "Form.hpp"

const char *Form::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!");
}
