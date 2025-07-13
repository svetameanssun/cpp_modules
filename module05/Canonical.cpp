#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other): _grade(other._grade), _name(other._name){
    std::cout << "Bureaucrat Copy Constructor Called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
    std::cout << "Bureaucrat " << _name << " assigned\n";
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << _name << " deeted\n";
}