#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);//this is not inherited from base class
    ShrubberyCreationForm&operator=(const ShrubberyCreationForm& other); //this is not inherited from base class
    ~ShrubberyCreationForm();

    const std::string& getTarget(void) const;

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor) const;

  private:
    const std::string &_target;
};

#endif
