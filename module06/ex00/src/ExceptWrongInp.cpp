#include "../include/ExceptWrongInp.hpp"

ExceptWrongInp::ExceptWrongInp(){}

ExceptWrongInp::ExceptWrongInp(const ExceptWrongInp &other){
    (void)other;
}

ExceptWrongInp &ExceptWrongInp::operator=(const ExceptWrongInp &other){
    (void)other;
    return (*this);
}

ExceptWrongInp::~ExceptWrongInp() throw(){}


const char *ExceptWrongInp::what()const throw(){
    return ("wrong input");
}
