#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // forward declaration

class Form {
  public:
    Form(): _name("FormName"), bool(false), _gradeForSign(150), _gradeForExec(150){};
    Form(const std::string &name, int gradeSign, int gradeExec);
    Form(const Form& other);
    Form&operator=(const Form& other);
    virtual ~Form();
    

      
    virtual beSigned(Bureaucrat &buro) = 0;
      
  private:
    const std::string _name;
    bool _signature;
    const int _gradeSign;
    const int _gradeExec;

}

#endif
