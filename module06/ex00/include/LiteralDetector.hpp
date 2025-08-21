#ifndef LITERALDETECTOR_HPP
#define LITERALDETECTOR_HPP

# include <iostream>
# include <string>
# include <limits> //std::numeric_limits<int>::max
# include <cstdlib> //atoi, atof, strtol, strtod, strtof
# include <cctype> // isprint, isdigit
# include <cmath> // isnan, isinf, fabs
# include <cerrno>
# include <math.h>
# include <cmath>
# include <climits>
# include <iomanip>
# include <bits/stdc++.h>
#include "../include/ScalarConverter.hpp"

class LiteralDetector{
  public:
    static bool isChar(std::string str, ScalarConverter::convRes &result);
    static bool isInt(std::string str, ScalarConverter::convRes &result);
    static bool isFloat(std::string str, ScalarConverter::convRes &result);
    static bool isDouble(std::string str, ScalarConverter::convRes &result);
  private:
    LiteralDetector();
    LiteralDetector(const LiteralDetector & other);
    LiteralDetector& operator=(const LiteralDetector &other);
    ~LiteralDetector();    
};

//I have to do it, in case of NAN, INF
void strToLow(std::string &str);

#endif
