#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Alina", 2);
        std::cout << a;
        a.incrGrade(); // Alina's grade = 1
        std::cout << a;
        a.incrGrade(); // throws GradeTooHighException
        std::cout << a;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    Bureaucrat b; //this will not throw any exception, because I set the values here
    try {
        //Bureaucrat b("Brad", 150);
        std::cout << b;
        b.decrGrade(); //  throws GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try {
        Bureaucrat c("Carlos", 0); //  throws GradeTooHighException in the constructor
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while creating Carlos: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try {
        Bureaucrat d("Diana", 151); //throws GradeTooLowException in the constructor
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while creating Diana: " << e.what() << std::endl;
    }

    return 0;
}

