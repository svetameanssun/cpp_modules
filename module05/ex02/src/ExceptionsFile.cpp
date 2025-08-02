#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

const char *Bureaucrat::GradeTooHighException::what()const throw(){
    return ("Burocrat cannot have such a high grade!\n");
}

const char *Bureaucrat::GradeTooLowException::what()const throw(){
    return ("Burocrat cannot have such a low grade!\n");
}

const char *AForm::GradeTooHighException::what()const throw(){
     return ("Form cannot have such a high grade!\n");
}

const char *AForm::GradeTooLowException::what()const throw(){
     return ("Form cannot have such a low grade!\n");
}

const char* AForm::PermissionDenied::what()const throw(){
    return ("The grade is too low for this action!\n");
}


