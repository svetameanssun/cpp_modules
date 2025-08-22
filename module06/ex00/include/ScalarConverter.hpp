#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
  public:
    static void convert(const std::string &literal);
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter&other);
    ~ScalarConverter();
  typedef struct convertResult{
      char c;
      int i;
      float f;
      double d;

      bool intFlag; // true if convertible to int, false is non-convertible to int
      int charFlag; // 1 = printable, 0  = non-printable, -1 = impossible
      //CHANGE THE LOGIC!
      //USE MACROS inff = INFINITY
      //           inf  = INFINITY
      //           -inff = -INFINITY
      //           -inf = -INFINITY
      //           nanf = nan = NAN
      bool specialFloat; // true if input == nan, inf , -inf
      bool speialDouble; // true if unput == nan, inf , -inf
      //convertResult()
      //  : c(0), i(0), intFlag(false), f(0.0f), d(0.0) {}
    } convRes;
};

std::ostream& operator<<(std::ostream& os, const struct convertResult& result);

#endif
