#include "RPN.hpp"

RPN::RPN() : result(0), inputStr(""), numbersStack(){}

RPN::RPN(const std::string &str): result(0), inputStr(str), numbersStack(){}

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

bool RPN::isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::run(int argc, char **argv){
    RCN rpnCalculator;
    if (argc > 1){
        for (int i = 0; i < argc; i++){
            std::string aux = argv[i]; 
            rpnCalculator.inputStr = rpnCalculator.inputStr + " " + aux;
        }
    }
    else if (argc == 1){
         rpnCalculator.inputStr = aux;
    }
    else{
        std::cerr << "Error: not enough args" << std::endl; 
        return;
    }
    for (int i = 0; i < rcnCalculator.inputStr.length(); i++){
        if (i == rpnCalculator.inputStr.length() - 1){
            if( numbersStack.size() == 1){
                std::cout << "The calculation result is " << this->result << std::endl
            }
            else{
                std::cerr << "Error: wrong input" << std::endl; 
                return;
            }
        }
        if (rpnCalculator.inputStr.at(i) == ' '){
            continue;
        }
        if (isdigit(rpnCalculator.inputStr.at(i))){
            std::sting auxString = rpnCalculator.inputStr.substr(i)
            std::stringstream ss(auxString);
            int auxNum;
            ss >> auxNum;
            if (auxNum > 9 || auxNum < 0){
                std::cerr << "Error: too big of a number" << std::endl; 
                return ;
            }
            numbersStack.push(auxNum);
        }
        else if (isOperator(rpnCalculator.inputStr.at(i)){
            if (numbersStack.size() < 2){
                std::cerr << "Error: wrong input" << std::endl; 
                return;
            }
        
            this->result = numbersStack.top();
            numbersStack.pop();
            if (c == '/'){
                if (this->result == 0){
                    std::cerr << "Error: cannot devide 0" << std::endl; 
                    return;
                }
                this->result = numbersStack.top() / this->result;
            }
            if (c == '-'){
                this->result = numbersStack.top() - this->result;
            }
            if (c == '+'){
                this->result = numbersStack.top() + this->result;
            }
            if (c == '*'){
                this->result = numbersStack.top() * this->result;
            }
            numbersStack.pop();
            numbersStack.push(this->result);
            } 
        }
        else{
            std::cerr << "Error: wrong input" << std::endl; 
            return;
        }
    }
}
