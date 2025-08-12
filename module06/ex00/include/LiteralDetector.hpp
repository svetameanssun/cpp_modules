#ifndef LITERALDETECTOR_HPP
#define LITERALDETECTOR_HPP

#include <iostream>
#include <string>
#include <limits> //std::numeric_limits<int>::max
#include <cstdlib> //atoi, atof, strtol, strtod, strtof
#include <cctype> // isprint, isdigit
#include <cmath> // isnan, isinf, fabs


class LiteralDetector{
  public:
    enum Type {CHAR, INT, FLOAT, DOUBLE, UNKNOWN};
    static bool isChar(std::string str);
    static bool isInt(std::string str);
    static bool isFloat(std::string str);
    static bool isDouble(std::string str);
  private:
    LiteralDetector(){};
    ~LiteralDetector(){};    
};

#endif
