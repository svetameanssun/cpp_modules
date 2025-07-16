#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Exception.hpp"


class Bureaucrat {
  public:
    Bureaucrat(): _name("DefaultName"), _grade(150) {};
    Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
      if (_grade > 150){
        throw GradeTooLowException();
      }
      if (_grade < 1){
        throw GradeTooHighException();
      }
    };
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string getName(void) const;
    int getGrade(void) const;
    //void setGrade(int grade);

    void incrGrade(void);
    void decrGrade(void);

    class GradeTooHighException: public std::exception{
      public:
        const char *what() const throw();
    };
      
    class GradeTooLowException: public std::exception{
      public:
        const char *what() const throw();
    };
  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& burocrat);

/* <name>, bureaucrat grade <grade>.*/
/*two member functions to increment or decrement the bureaucrat’s grade.*/

/*Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.*/

#endif
