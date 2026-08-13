#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(std::string name, int gradeForSign, int gradeForExec)
    : _name(name), _signature(false), _gradeForSign(gradeForSign), _gradeForExec(gradeForExec) {
    if (_gradeForSign < 1 || _gradeForExec < 1)
        throw GradeTooHighException();
    if (_gradeForSign > 150 || _gradeForExec > 150)
        throw GradeTooLowException();
    std::cout << _name << " created\n";
    
}


Form::Form(const Form &other)
    : _name(other._name),
      _signature(other._signature),
      _gradeForSign(other._gradeForSign),
      _gradeForExec(other._gradeForExec) {}

Form& Form::operator=(const Form &other) {
    if (this != &other) {
        _signature = other._signature;
        // _name, _gradeForSign, _gradeForExec are const and cannot be reassigned
    }
    return *this;
}

Form::~Form() {
    std::cout << getName() << " deleted\n";
}

const std::string &Form::getName(void) const {
    return (_name);
}

bool Form::getSignature(void) const {
    return(_signature);
}

const int& Form::getGradeForSign(void) const {
    return (_gradeForSign);
}

const int &Form::getGradeForExec(void) const {
    return (_gradeForExec);
}

const char *Form::GradeTooHighException:: what() const throw(){
    return ("Grade is too high!\n");
}

const char *Form::GradeTooLowException:: what() const throw(){
    return ("Grade is too low!\n");
}


std::ostream& operator<<(std::ostream &os, const Form &formy) {
    os << formy.getName() << ":\n"
       << "grade required to sign it: " << formy.getGradeForSign() << "\n"
       << "grade required to execute it: " << formy.getGradeForExec() <<  "\n";
    if(formy.getSignature()) {
        os << "The form is signed\n";
    } else {
        os << "The form is unsigned\n";
    }
    return (os);
}

void Form::beSigned(Bureaucrat& buro) {
    if(buro.getGrade() > getGradeForSign()) {
        throw GradeTooLowException();
    }
    _signature = true;
}

