#include "../include/LiteralDetector.hpp"

void strToLow(std::string &str){
  int ind = 0;
  for(; ind < (int)str.length(); ++ind){
    if (isupper(str[ind])){
        str.at(ind) = tolower(str.at(ind));
    }
  }
}

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
    int index = 0;
    int strLen = str.length();
    long int myInt;
    if (str.at(index) == '-' || str.at(index) == '+'){
        index++;
    }
    while (index < strLen){
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
    long double inputNbr;
    
    strToLow(str);
    if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff"){
      return true;
    }
    
    if (str.at(strLen - 1) != 'f' && str.at(strLen - 1) != 'F'){
        return (false);
    }
    int i = 0;
    if (str.at(i) == '-'|| str.at(i) == '+'){
        i++;
    }

    for (; i < strLen - 1; ++i){
        if (str.at(i) == '.'){
            countDots++;
            dotPos = i;
        }
        if (str.at(i) != '.' && !isdigit(str.at(i))){
            return (false);
        }
    }

    if (countDots != 1 || dotPos == 0){
        return (false);
    }
    inputNbr = std::strtold(str.c_str(), NULL);
    if (inputNbr > std::numeric_limits<float>::max() || inputNbr < std::numeric_limits<float>::min()){
        return (false);
    }
    return (true);
}

bool LiteralDetector::isDouble (std::string str){
    int countDots = 0;
    int dotPos = 0;
    int strLen = str.length();
    long double inputNbr;
    
    strToLow(str);
    int i = 0;
    
    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf"){
      return true;
    }    
    if (str.at(i) == '-'|| str.at(i) == '+'){
        i++;
    }

    for (; i < strLen; ++i){
        if (str.at(i) == '.'){
            countDots++;
            dotPos = i;
        }
        if (str.at(i) != '.' && !isdigit(str.at(i))){
            return (false);
        }
    }

    if (countDots != 1 || dotPos == 0){
        return (false);
    }
    inputNbr = std::strtold(str.c_str(), NULL);
    if (inputNbr > std::numeric_limits<double>::max() || inputNbr < std::numeric_limits<double>::min()){
        return (false);
    }
    return (true);
}


