#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream> 
#include <string>
#include <stack>
#include <cstring>
#include <bits/stdc++.h>

class RPN {
  public:
    RPN();
    RPN(const std::string &str);
    RPN(const RPN &other);
    RPN & operator=(const RPN &other);
    ~RPN();

    void run(char **str);
    bool isOperator(char c);
  private:
    int result;
    std::string inputStr; 
    std::stack<int> numbersStack;
};

#endif
