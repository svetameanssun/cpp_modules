#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
class Bureaucrat;// forward declaration

class Form {
  public:
    Form(): _name("DefaultName"), _signature(false), _gradeForSign(1), _gradeForExec(2){};
    Form(std::string name, bool signature, int gradeForSign, int gradeForExec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    const std::string &getName(void) const;
    bool getSignature(void) const;
    const int &getGradeForSign(void) const;
    const int &getGradeForExec(void) const;
    
    class GradeTooHighException : public std::exception{
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what()const throw();
    };
    void beSigned(Bureaucrat &buro);
  private:
    const std::string _name;
    bool _signature;
    const int _gradeForSign;
    const int _gradeForExec;
};

std::ostream& operator<<(std::ostream &os,const Form &formy);
/*
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.


As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.
*/


#endif
