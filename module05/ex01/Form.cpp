#include "Form.hpp"

Form::Form(name, gradeForSign, gradeForExec): _name(name), _signature(false), _gradeForSing(getGradeForSing), _gradeForExec(getGradeForExec) {
    if(_gradeForSing < 1) {
        throw GradeTooHighException();
    }
    if(_gradeForSing < 1) {
        throw GradeTooHighException();
    }
    if(_gradeForSing > 150) {
        throw GradeTooHighException();
    }
    if(_gradeForSing > 150) {
        throw GradeTooHighException();
    }
    std::cout << getName() << " created\n";
}

Form::Form(const Form &other) {
    _bool = other._signature;
}

Form &Form::operator=(const Form &other) {
    if(this != NULL) {
        _signature = other._signature;
    }
    return (*this);
}

Form::~Form() {
    std::cout << getName() << " deleted\n";
}

const std::string Form::getName(void) {
    return (_name);
}

bool Form::getSignature(void) {
    return(_signature);
}

const int Form::getGradeForSing(void) {
    return (_gradeForSing);
}

const int Form::getGradeForExec(void) {
    return (_gradeForExec);
}

std::ostream& operator<<(std::ostream &os, Form &formy) {
    /*if (formy.getSignature){
        os << formy.getName() ":\n"
        << "grade required to sign it: " << formy.getGradeForSing() << "\n"
        << "grade required to execute it: " << formy.getGradeForExec() <<  "\n"
        << "The form is signed\n";
    }
    else{
        os << formy.getName() ":\n"
        << "grade required to sign it: " << formy.getGradeForSing() << "\n"
        << "grade required to execute it: " << formy.getGradeForExec() <<  "\n"
        << "The form is unsigned\n";
    }*/
    os << formy.getName() ":\n"
       << "grade required to sign it: " << formy.getGradeForSing() << "\n"
       << "grade required to execute it: " << formy.getGradeForExec() <<  "\n"
    if(formy.getSignature) {
        os << "The form is signed\n";
    } else {
        os << "The form is unsigned\n";
    }
    return (os);
}

void Form::beSigned(Bureaucrat& buro){
    if (buro.getGrade() > getGradeForSign()){
        throw GradeTooLowException();
    }
    _signature = true;

}

/*Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
*/
