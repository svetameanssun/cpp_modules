#include "../include/LiteralDetector.hpp"

// CONVERT ALL STRING UPPER CASE TO LOWER CASE 
void strToLow(std::string &str){
  int ind = 0;
  for(; ind < (int)str.length(); ++ind){
    if (isupper(str[ind])){
        str.at(ind) = tolower(str.at(ind));
    }
  }
}

// ----- IS CHAR -----
bool LiteralDetector::isChar(std::string str,  ScalarConverter::convRes &result){
  if (str.length() == 1 && !std::isdigit(str.at(0))){
    result.c = literal[0];
    return true;
  }
  if (str.length() == 3 && str.at(0) == '\''
      && str.at(2) == '\'' && !std::isdigit(str.at(1))){
    result.c = literal[1];
    return true;
  }
  return false;
}

// ----- IS INT -----
bool LiteralDetector::isInt(std::string str, ScalarConverter::convRes &result){
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
   // STR TO INT
    result.i = atoi(literal.c_str());
    result.intFlag = true;
    return true;
}

// ----- IS FLOAT -----
bool LiteralDetector::isFloat(std::string str, ScalarConverter::convRes &result){

    int countDots = 0;
    int dotPos = 0;
    int strLen = str.length();
    long double inputNbr;
    
    result.floatFlag = NULL; 
    strToLow(str);
    if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff"){
      result.floatFlag = str;
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
     // STR TO FLOAT
    str.erase(literal.length() - 1, 1);
    result.f = std::atof(str.c_str()); // I have to print 'f' after this one!
    return (true);
}

// ----- IS DOUBLE -----
bool LiteralDetector::isDouble (std::string str, ScalarConverter::convRes &result){
    int countDots = 0;
    int dotPos = 0;
    int strLen = str.length();
    long double inputNbr;

    result.doubleFlag = NULL;
    strToLow(str);
    int i = 0;
    
    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf"){
      result.doubleFlag = str;
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
    // STR TO DOUBLE
    std::stringstream ss(str);
    result.d  = 0.0;
    ss >> result.d;
    return (true);
}


