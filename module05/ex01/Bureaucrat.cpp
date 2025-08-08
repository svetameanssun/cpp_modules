#include "Common.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    _grade = grade;
    std::cout << "Bureaucrat " << getName() << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name){
    _grade = other._grade;
    std::cout << "Bureaucrat copy contructor called!\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        //_name = other._name; //cannot redefine a const parameter
        _grade = other._grade; //trying this, instead of getName();
    }
    std::cout << "Bureacrat " << getName() << " assigned\n";
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << getName() << " deleted\n";
}

const std::string& Bureaucrat::getName(void) const{
    return (_name);
}

int Bureaucrat::getGrade(void) const{
    return (_grade);
}

void Bureaucrat::incrGrade(void){
    if (_grade - 1 == 0){
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrGrade(void){
    if (_grade + 1 == 151){
        throw GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(Form& form){
    try{
        form.beSigned(*this);
        std::cout << "bureaucrat " << getName() <<" signed form " << form.getName() << "\n";
    } catch (const std::exception &e){
        std:: cerr << "bureaucrat " << getName() <<" couldn’t sign form " << form.getName() << ", because " << e.what();
    }
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat&burocrat){
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return (os);
}


