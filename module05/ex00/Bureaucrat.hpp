#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
  public:
    Bureaucrat(): _name("DefaultName"), _grade(150) {};
    Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {};
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat&operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string getName(void) const;
    int getGrade(void) const;
    void setGrade(int grade);

    void incrGrade(void);
    void decrGrade(void);

    void GradeTooHighException(void);
    void GradeTooLowException(void);

    

  private:
    const std::string _name;
    int _grade;
};

class CustomExcept {
  public:
    CustomExcept(const std::string& msg) : message(msg) {}

    // Handle custom exception using what() method.
    const char* what() const {
        return message.c_str();
    }

  private:
    std::string message;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& burocrat);

/* <name>, bureaucrat grade <grade>.*/
/*two member functions to increment or decrement the bureaucrat’s grade.*/

/*Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.*/

#endif