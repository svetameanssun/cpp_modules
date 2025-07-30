#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(cosnt std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void beSigned(Bureaucrat const  &buro);
    void execute(Bureaucrat const & executor) const;
};

#endif
