#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
  public:
    RPN();
    RPN(const std::string &str);
    RPN(const RPN &other);
    RPN & operator=(const RPN &other);
    ~RPN();
  private:
    int result;
    const std::string& inputStr; 
    std::stack<int> numbersStack;
};

#endif
