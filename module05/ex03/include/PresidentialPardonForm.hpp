#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm {
  public:
   PresidentialPardonForm(const std::string &target);
   PresidentialPardonForm(const PresidentialPardonForm& other);//this is not inherited from base class
    PresidentialPardonForm&operator=(const PresidentialPardonForm& other); //this is not inherited from base class
    ~PresidentialPardonForm();

    const std::string& getTarget(void) const;

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor);

  private:
    const std::string &_target;  
};
#endif
