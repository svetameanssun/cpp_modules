#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
class AForm;

class Bureaucrat {
  public:
    // -- CANONICAL FORM --
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // -- GETTERS --
    const std::string & getName(void) const;
    int getGrade(void) const;

    // -- GRADE UP/DOWN --
    void incrGrade(void);
    void decrGrade(void);

    // -- SIGN FORM --
    void signForm(AForm &form) const;
    void executeForm(AForm const & form) const;

    // -- EXCEPTIONS --
    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();

    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& buro);

#endif
