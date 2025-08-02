#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm(const std::string &target);
   RobotomyRequestForm(const RobotomyRequestForm& other);//this is not inherited from base class
    RobotomyRequestForm&operator=(const RobotomyRequestForm& other); //this is not inherited from base class
    ~RobotomyRequestForm();

    const std::string& getTarget(void) const;

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor);
    int getSerialNum(void) const;
    void incrSerialNum(void);

  private:
    const std::string &_target;
    static int _serialNum;
    
};

#endif
