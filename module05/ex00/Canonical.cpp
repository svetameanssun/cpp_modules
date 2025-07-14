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