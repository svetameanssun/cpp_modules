#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm(cosnt std::string &target);
   RobotomyRequestForm(const RobotomyRequestForm& other);//this is not inherited from base class
    RobotomyRequestForm&operator=(const RobotomyRequestForm& other); //this is not inherited from base class
    ~RobotomyRequestForm();

    const std::string& getName(void) const;

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor) const;
    static int getSerialNum(void) const;
    void incrSerialNum(void);

  private:
    const std::string &_target;
    static int _serialNum;
    
};

#endif
