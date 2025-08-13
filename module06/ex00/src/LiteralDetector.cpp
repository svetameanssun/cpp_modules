#include "LiteralDetector.hpp"

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
    int minIntLen = 11;
    int maxIntLen = 10;
    int index = 0;
    int endPoint;
    long int myInt;
    if ((int)str.length() == minIntLen && str.at(index) == '-'){
        index++;
    }
    else{
        if ((int)str.length() > maxIntLen){
            return (false);
        }
    }
    if (index == 1){
        endPoint = minIntLen;
    }
    else{
        endPoint = maxIntLen;
    }
    while (index < endPoint){
        if (!isdigit(str[index])){
            return false;
        }
        index++;
    }
    myInt = atol(str.c_str());
    if (myInt > (long)std::numeric_limits<int>::max() || myInt < (long)std::numeric_limits<int>::min()){
        return (false);
    }
    return true;
}

bool LiteralDetector::isFloat(std::string str){
    int countDots = 0;
    int dotPos = 0;
    int strLen = str.length();
    if (str.at(str.length() - 1) != f){
      return (false);
    }
    char dot = '.';
    int countDots = std::count(str.begin(), str.end(), dot);
    if (countDots != 1){
        return (false);
    }
    dotPos = str.find(dot, 0);
    if (dotPos == std::string::npos)
    {
      return (false);
    }
    
    return (true);
}

bool LiteralDetector::isDouble (std::string str){
  
}


