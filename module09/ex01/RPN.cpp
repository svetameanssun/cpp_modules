#include "RPN.hpp"

RPN::RPN() : result(0), inputStr(""), numbersStack() {}

RPN::RPN(const std::string &str) : result(0), inputStr(str), numbersStack() {}

RPN::RPN(const RPN &other) 
    : result(other.result), inputStr(other.inputStr), numbersStack(other.numbersStack) {}

RPN & RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->result = other.result;
        this->inputStr = other.inputStr;
        this->numbersStack = other.numbersStack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::run(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            this->inputStr += argv[i];
            if (i < argc - 1) this->inputStr += " ";
        }
    } else {
        std::cerr << "Error: not enough args" << std::endl;
        return;
    }

    for (size_t i = 0; i < this->inputStr.length(); i++) {
        char c = this->inputStr.at(i);

        if (c == ' ') continue;

        if (isdigit(c)) {
            int num = c - '0';
            numbersStack.push(num);
        } 
        else if (isOperator(c)) {
            if (numbersStack.size() < 2) {
                std::cerr << "Error: wrong input" << std::endl;
                return;
            }

            int rightOp = numbersStack.top();
            numbersStack.pop();
            int leftOp = numbersStack.top();
            numbersStack.pop();

            if (c == '/') {
                if (rightOp == 0) {
                    std::cerr << "Error: division by zero" << std::endl;
                    return;
                }
                this->result = leftOp / rightOp;
            }
            else if (c == '-') this->result = leftOp - rightOp;
            else if (c == '+') this->result = leftOp + rightOp;
            else if (c == '*') this->result = leftOp * rightOp;

            numbersStack.push(this->result);
        } 
        else {
            std::cerr << "Error: invalid char" << std::endl;
            return;
        }
    }
    if (numbersStack.size() == 1) {
        std::cout << numbersStack.top() << std::endl;
    } else {
        std::cerr << "Error: too many operands" << std::endl;
    }
}
