#include "Form.hpp"

Form::Form(std::string name, bool signature, int gradeForSign, int gradeForExec): _name(name), _gradeForSign(gradeForSign), _gradeForExec(gradeForExec) {
    if(signature) {
        std::cout << "At construction teh form cannot be signed.\n Alas! I have to set the _signature to false!\n";
        signature = false;
    }
    _signature = signature;
    if(_gradeForSign < 1 || _gradeForExec < 1) {
        throw GradeTooHighException();
    }
    if(_gradeForSign > 150 || _gradeForExec > 150) {
        throw GradeTooLowException();
    }
    std::cout << getName() << " created\n";
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

std::ostream& operator<<(std::ostream &os, const Form &formy) {
    /*if (formy.getSignature){
        os << formy.getName() ":\n"
        << "grade required to sign it: " << formy.getGradeForSign_gradeForSign() << "\n"
        << "grade required to execute it: " << formy.getGradeForExec() <<  "\n"
        << "The form is signed\n";
    }
    else{
        os << formy.getName() ":\n"
        << "grade required to sign it: " << formy.getGradeForSign_gradeForSign() << "\n"
        << "grade required to execute it: " << formy.getGradeForExec() <<  "\n"
        << "The form is unsigned\n";
    }*/
    os << formy.getName() << ":\n"
       << "grade required to sign it: " << formy.getGradeForSign_gradeForSign() << "\n"
       << "grade required to execute it: " << formy.getGradeForExec() <<  "\n";
    if(formy.getSignature) {
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

/*Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
*/
