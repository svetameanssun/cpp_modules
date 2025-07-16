#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade > 150){
        throw GradeTooLowException();
    }
    if (grade < 0){
        throw GradeTooHighException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){
    std::cout << "Bureaucrat Copy Constructor Called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
    {
        //_name = other.getName();
        _grade = other.getGrade();
    }
    std::cout << "Bureaucrat " << getName() << " assigned\n";
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << getName() << " deleted\n";
}

const std::string Bureaucrat::getName(void) const {
    return(_name);
}

int Bureaucrat::getGrade(void) const {
    return(_grade);
}

/*void Bureaucrat::setGrade(int grade){
    _grade = grade;
}*/


void Bureaucrat::incrGrade(void) {
    if (_grade - 1 <= 0){
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrGrade(void) {
    if (_grade + 1>=150){
        throw GradeTooLowException();
    }
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& burocrat) {
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return os;
}
