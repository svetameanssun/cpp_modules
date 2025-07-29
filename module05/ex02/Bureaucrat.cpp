#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Name"), _grade(150) {
    std::cout << "Bureaucrat " << getName() << " constructed by default\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name){
    _grade = grade;
    std::cout << "Bureaucrat " << getName() << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat & other){
    _grade = other._grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat&other){
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

void Bureaucrat::signForm(Form& form){
    
}

std::ostream&operator<<(std::ostream&os, const Bureaucrat &buro){
    
}
