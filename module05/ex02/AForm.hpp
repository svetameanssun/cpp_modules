#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // forward declaration

class AForm {
  public:
    // -- CANONICAL FORM --
    AForm(const std::string &name, int gradeSign, int gradeExec, const std::string &target);
    AForm(const AForm& other);
    AForm&operator=(const AForm& other);
    virtual ~AForm();

    // -- GETTERS --
    const std::string &getName(void) const;
    bool isSigned(void) const;
    const int getGradeSign(void) const;
    const int getGradeExec(void) const;
    const std::string &getTarget(void) const;

    // -- FORM FUNCTIONS --
    virtual void beSigned(Bureaucrat const  &buro) = 0;
    virtual void execute(Bureaucrat const & executor) const = 0;

    // -- EXCEPTION CLASSES --
    class GradeTooLowException : public std::exception {
      public:
        const char* what() const throw();
    };
    class GradeTooHighException: public std::exception {
      public:
        const char* what() const throw();
    };

    class PermissionDenied: public std::exception {
      public:
        const char* what const throw();
    }
  private:
    const std::string _name;
    bool _signature;
    const int _gradeSign;
    const int _gradeExec;
    const std::string _target;
};

std::ostream & operator<<(std::ostream &os, const AForm &formy);

#endif
