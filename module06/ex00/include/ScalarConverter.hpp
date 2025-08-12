#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter{
  public:
    static void convert(const std::string &literal);
  private:
    ScalarConverter(){};
    ~ScalarConverter(){};
};

#endif
