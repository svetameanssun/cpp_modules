#include "LiteralDetector.hpp"

static bool LiteralDetector::isChar(std::string str){
  if (str.length() == 1 && !std::isdigit(str.at(0))){
    return true;
  }
  if (str.length() == 3 && str.at(0) == "'"
      && str.at(2) == "'" && !std::isdigit(str.at(1))){
    return true;
  }
  return false;
}

static bool LiteralDetector::isInt(std::string str){
  
}

static bool LiteralDetector::isFloat(std::string str){
  
}

static bool LiteralDetector::isDouble (std::string str){
  
}
