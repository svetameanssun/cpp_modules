#ifndef FORM_HPP
#define
#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
  public:
    Form() _name("DefaultName"), _signature(false), _gradeForSing(1), _gradeForExec(2);
    Form(name, gradeForSign, gradeForExec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    const std::string getName(void);
    bool getSignature(void);
    const int getGradeForSing(void);
    const int getGradeForExec(void);
    
    class GradeTooHighException {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException {
      public:
        const char *what()const throw();
    };
    void beSigned(Bureaucrat &buro);
  private:
    const std::string _name;
    bool _signature;
    const int _gradeForSing;
    const int _gradeForExec;
};

std::ostream& operator<<(std::ostream &os,Form &formy);
/*
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.


As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.
*/


#endif