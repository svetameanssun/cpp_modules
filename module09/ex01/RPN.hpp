#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>

class RPN{
    public:
        RPN();
        RPN(const std::string &str);
        ~RPN();
    private:
        int result;

};

#endif