#include "Bureaucrat.hpp"

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
    _grade--;
    GradeTooHighException();

}

void Bureaucrat::decrGrade(void) {
    _grade++;
    GradeTooLowException();

}

void Bureaucrat::GradeTooHighException(void) {
    try {
        if(_grade < 1) {
            throw CustomExcept(
                "Bureaucrat::GradeTooHighException\n"
            );
        }
    } catch(const CustomExcept& e) {
        std::cout << getName() << ": "<< e.what();
    }

}

void Bureaucrat::GradeTooLowException(void) {
    try {
        if(_grade > 150) {
            throw CustomExcept(
                "Bureaucrat::GradeTooLowException\n"
            );
        }
    } catch(const CustomExcept& e) {
        std::cout << getName() << ": "<< e.what();
    }

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& burocrat) {
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return os;
}