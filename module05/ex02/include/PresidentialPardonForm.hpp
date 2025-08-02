#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  public:
   PresidentialPardonForm(cosnt std::string &target);
   PresidentialPardonForm(const PresidentialPardonForm& other);//this is not inherited from base class
    PresidentialPardonForm&operator=(const PresidentialPardonForm& other); //this is not inherited from base class
    ~PresidentialPardonForm();

    const std::string& getName(void) const;

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor) const;

  private:
    const std::string &_target;
    static int _serialNum;
    
};
#endif
