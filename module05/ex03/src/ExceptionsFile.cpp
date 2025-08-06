#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

const char *Bureaucrat::GradeTooHighException::what()const throw(){
    return ("grade is too high\n");
}

const char *Bureaucrat::GradeTooLowException::what()const throw(){
    return ("grade is too low\n");
}

const char *AForm::GradeTooHighException::what()const throw(){
     return ("required grade is too high\n");
}

const char *AForm::GradeTooLowException::what()const throw(){
     return ("required grade is too low\n");
}

const char* AForm::PermissionDeniedToSign::what()const throw(){
    return ("bureaucrat's grade is too low to sign\n");
}
const char* AForm::PermissionDeniedToExec::what()const throw(){
    return ("bureaucrat's grade is too low to execute\n");
}


