#include "Bureaucrat.hpp"


const std::string Bureaucrat::getName(void) const {
    return(_name);
}

int Bureaucrat::getGrade(void) const {
    return(_grade);
}

void Bureaucrat::setGrade(int grade){
    _grade = grade;
}


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
        std::cout << "Caught an exception: " << e.what();
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
        std::cout << "Caught an exception: " << e.what();
    }

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& burocrat) {
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return os;
}