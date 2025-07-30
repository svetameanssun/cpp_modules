#include "AForm.hpp"
#include "Bureaucrat.hpp"

 AForm::AForm(const std::string &name, int gradeSign, int gradeExec, const std::string &target):
                    _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _target(target){
   _signature = false;
 }
