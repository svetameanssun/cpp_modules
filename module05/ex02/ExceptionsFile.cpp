#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(){
    return ("Burocrat cannot have such a high grade!\n");
}

const char *Bureaucrat::GradeTooLowException::what(){
    return ("Burocrat cannot have such a low grade!\n");
}

const char *AForm::GradeTooHighException::what(){
     return ("Form cannot have such a high grade!\n");
}

const char *AForm::GradeTooLowException::what(){
     return ("Form cannot have such a low grade!\n");
}
