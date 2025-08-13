#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
  public:
    typedef struct ConvertResult{
      char c;
      int i;
      float f;
      double d;
    };
    static void convert(const std::string &literal);
  private:
    ScalarConverter(){};
    ~ScalarConverter(){};
};

#endif
