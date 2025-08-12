#ifndef LITERALDETECTOR_HPP
#define LITERALDETECTOR_HPP

#include <iostream>
#include <string>
#include <limits>
//numeric_limits<int>::max

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

bool LiteralDetector::isChar(std::string str){
  if (str.length() == 1 && !std::isdigit(str.at(0))){
    return true;
  }
  if (str.length() == 3 && str.at(0) == '\''
      && str.at(2) == '\'' && !std::isdigit(str.at(1))){
    return true;
  }
  return false;
}

bool LiteralDetector::isInt(std::string str){
  
}

bool LiteralDetector::isFloat(std::string str){
  
}

bool LiteralDetector::isDouble (std::string str){
  
}

#endif
