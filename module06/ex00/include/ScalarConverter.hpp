#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
  public:
    typedef struct convertResult{
      char c;
      int i;
      bool intFlag; // true if convertible to int, false is non-convertible to int
      float f;
      double d;
    } convRes;
    static void convert(const std::string &literal);
  private:
    ScalarConverter(){};
    ~ScalarConverter(){};
};

std::ostream& operator<<(std::ostream& os, const struct convertResult& result);

#endif
