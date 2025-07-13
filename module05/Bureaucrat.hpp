#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat{
    public:
        Bureaucrat(): _name("DefaultName"), _grade(150) {};
        Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {};
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat&operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        const std::string getName(void) const;
        int getGrade(void) const;

        void incrGrade(void);
        void decrGrade(void);
        
        void GradeTooHighException(void);
        void GradeTooLowException(void);

        ostream& operator<<(ostream& os, const Bureaucrat& burocrat);

    private:
        const std::string _name;
        int _grade;
};

ostream& operator<<(ostream& os, const Bureaucrat& burocrat)
{
    os << burocrat._name << ", bureaucrat grade " << burocrat._grade << '.' << '\n';
    return os;
}

/* <name>, bureaucrat grade <grade>.*/
/*two member functions to increment or decrement the bureaucrat’s grade.*/

/*Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.*/

#endif