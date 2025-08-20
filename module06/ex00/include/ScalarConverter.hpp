#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
  public:
    typedef struct convertResult{
      char c;
      int i;
      float f;
      double d;
      bool intFlag; // true if convertible to int, false is non-convertible to int
      int charFlag; // 1 = printable, 0  = non-printable, -1 = impossible
      std::string floatFlag; // if !NULL, print flag in the output
      std::string doubleFlag; // if !NULL, print flag in the output
      //convertResult()
      //  : c(0), i(0), intFlag(false), f(0.0f), d(0.0) {}
    } convRes;
    static void convert(const std::string &literal);
  private:
    ScalarConverter(){};
    ~ScalarConverter(){};
};

std::ostream& operator<<(std::ostream& os, const struct convertResult& result);

#endif
