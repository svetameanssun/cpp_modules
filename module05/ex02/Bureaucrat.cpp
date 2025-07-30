#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Name"), _grade(150) {
    std::cout << "Bureaucrat " << getName() << " constructed by default\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    _grade = grade;
    std::cout << "Bureaucrat " << getName() << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat & other){
    _grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat&other){
    if (this != &other){
        _grade = other._grade;
    }
    return (*this);
}

const std::string& Bureaucrat::getName(void) const{
    return(_name);
}

int Bureaucrat::getGrade(void) const{
    return(_grade);
}

void Bureaucrat::incrGrade(){
    if (_grade - 1 == 0)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrGrade(){
    if (_grade + 1 == 151)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const{
    if (Bureaucrat._grade > form._gradeSign){
       throw form.PermissionDenied();
    }
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << "\n";   
    
}

void executeForm(AForm const & form) const{
    if (Bureaucrat._grade > form._gradeExec){
        throw (form.PermissionDenied());
    }
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << "\n";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat&burocrat){
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return (os);
}