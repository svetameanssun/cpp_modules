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
    int dotFlag = 0;
    int strLen = str.length();
    for (int i = 0; i < strLen; i++){
        if (str.at(i) == '.'){
            dotFlag++;
        }
    }
    if (dotFlag != 1){
        return (false);
    }
    i = 0;
    
    
    
    
    return (true);
    
  
}

bool LiteralDetector::isDouble (std::string str){
  
}


