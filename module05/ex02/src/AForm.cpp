#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"


AForm::AForm(const std::string &name, int gradeSign, int gradeExec):
    _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    try {
    if (gradeSign < 1 || gradeExec < 1){
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExec > 150){
        throw GradeTooLowException();
    }
    _signature = false;
    }
    catch (std::exception &e){
        std::cerr << "Couldn't create AForm " << getName() << ", because " << e.what() << "\n";
    }
}

AForm::AForm(const AForm& other):
    _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
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

const int &AForm::getGradeSign(void) const {
    return (_gradeSign);
}

const int &AForm::getGradeExec(void) const {
    return (_gradeExec);
}

void AForm::setSignature(bool value) {
    _signature = value;
}

bool AForm::getSignature() const {
    return _signature;
}

const char *AForm::GradeTooHighException::what()const throw(){
     return ("required grade is too high\n");
}

const char *AForm::GradeTooLowException::what()const throw(){
     return ("required grade is too low\n");
}

const char* AForm::PermissionDeniedToSign::what()const throw(){
    return ("bureaucrat's grade is too low to sign\n");
}
const char* AForm::PermissionDeniedToExec::what()const throw(){
    return ("bureaucrat's grade is too low to execute\n");
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

