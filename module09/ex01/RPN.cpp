#include "RPN.cpp"

RPN::RPN() : result(0), inputStr(""), numberStack(){}

RPN::RPN(const std::string &str): result(0), inputStr(str), numberStack(){}

// Copy Constructor
// Note: You don't check for self-assignment in a constructor 
// because the object is just being born; it can't be itself yet.
RPN::RPN(const RPN &other) 
    : result(other.result), inputStr(other.inputStr), numbersStack(other.numbersStack) {
}

// Assignment Operator
RPN & RPN::operator=(const RPN &other) {
    // Check for self-assignment (e.g., a = a)
    if (this != &other) {
        this->result = other.result;
        this->inputStr = other.inputStr;
        this->numbersStack = other.numbersStack;
    }
    return *this;
}

RPN::~RPN() {}
