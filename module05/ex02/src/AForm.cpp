#include "AForm.hpp"
#include "Bureaucrat.hpp"

#ifdef USE_CONSTRUCTOR_TRY_BLOCK

void logError(const std::string & message){
    std::
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
    try: _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signature(false){
    if (gradeSign < 1 || gradeExec < 1){
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExec > 150){
        throw GradeTooLowException();
    }
    std::cout << "AForm " << getName() << " constructed\n";
}
catch (const std::exception &e) {
    logError("Error in Bureaucrat: " + std::string(e.what()));
    throw;
}

#else

AForm::AForm(const std::string &name, int gradeSign, int gradeExec):
    _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1){
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExec > 150){
        throw GradeTooLowException();
    }
    _signature = false;
}

#endif
AForm::AForm(const AForm& other) {
    _signature = other._signature;
}

AForm& AForm::operator=(const AForm& other) {
    if(this != &other) {
        _signature = other._signature;
    }
    return (*this);
}

AForm::~AForm() {};

const std::string& AForm::getName(void) const {
    return (_name);
}

bool AForm::isSigned(void) const {
    return (_signature);
}

const int AForm::getGradeSign(void) const {
    return (_gradeSign);
}

const int AForm::getGradeExec(void) const {
    return (_gradeExec);
}

std::ostream &operator<<(std::ostream &os, const AForm &formy) {
    os << formy.getName() << ":\n"
       << "grade required to sign it: " << formy.getGradeSign() << "\n"
       << "grade required to execute it: " << formy.getGradeExec() <<  "\n";
    if(formy.isSigned()) {
        os << "The form is signed\n";
    } else {
        os << "The form is unsigned\n";
    }
    return (os);
}
