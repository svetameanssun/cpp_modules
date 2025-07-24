#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"
#include "ExceptionBuro.hpp"

class Bureaucrat {
  public:
    Bureaucrat(): _name("DefaultName"), _grade(150) {};
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const &std::string getName(void) const;
    int getGrade(void) const;
    
    void incrGrade(void);
    void decrGrade(void);
    void signForm(Form& form);
    
    class GradeTooHighException : public std::exception{
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
            const char * what() const throw();
    };

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& burocrat);

/*
Then, modify the signForm() member function in the Bureaucrat class. This func-
tion must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and submit some tests to ensure everything works as expected.
*/

#endif
