#include "../include/LiteralDetector.hpp"
#include "../include/ScalarConverter.hpp"

LiteralDetector::LiteralDetector() {}
LiteralDetector::LiteralDetector(const LiteralDetector & other){
  (void)other;
}
LiteralDetector& LiteralDetector::operator=(const LiteralDetector &other){
  (void)other;
  return (*this);
}
LiteralDetector::~LiteralDetector(){}

// CONVERT ALL UPPER CASE CHARS IN STR TO LOWER CASE 
void strToLow(std::string &str){
  int ind = 0;
  for(; ind < (int)str.length(); ++ind){
    if (isupper(str[ind])){
        str.at(ind) = tolower(str.at(ind));
    }
  }
}

int charStatus(int myInt){

      if (myInt >= 33 && myInt <= 126){
       // normal
        return 1;
      }
      else if((myInt >= 0 && myInt < 33) || myInt == 127)
      {
        // Non displayable
        return 0;
      } 
      else{
        return -1;
      }
}

bool intStatus(float myFloat){
      if (myFloat > (long)std::numeric_limits<int>::max() || myFloat < (long)std::numeric_limits<int>::min()){
      return false;
    }
    else{
      return true;
    }
}
bool intStatus(double myDouble){
  if (myDouble > (long)std::numeric_limits<int>::max() || myDouble < (long)std::numeric_limits<int>::min()){
      return  false;
    }
    else{
      return true;
    }
}

// ----- IS CHAR -----
bool LiteralDetector::isChar(std::string str,  ScalarConverter::convRes &result){
  
  if (str.length() == 1 && !std::isdigit(str.at(0))){
    result.c = str[0];
    result.charFlag = 1;
    result.intFlag = true;
    return true;
  }
  if (str.length() == 3 && str.at(0) == '\''
      && str.at(2) == '\'' && !std::isdigit(str.at(1))){
    result.c = str[1];
    result.charFlag = 1;
    result.intFlag = true;
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
    result.i = atoi(str.c_str());
    result.intFlag = true;
    return true;
}

// ----- IS FLOAT -----
bool LiteralDetector::isFloat(std::string str, ScalarConverter::convRes &result){

    int countDots = 0;
    int strLen = str.length();
    long double inputNbr;
    
    strToLow(str);
    if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff"){
      if (str == "nanf")
        result.f = NAN;
      if (str == "+inff" || str == "inff")
        result.f = INFINITY;
      if (str == "-inff")
        result.f = -INFINITY;
      result.specialFloat = true;
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
        }
        if (str.at(i) != '.' && !isdigit(str.at(i))){
          
          return (false);
        }
    }
    if ((str.at(strLen - 1) == 'f' || str.at(strLen - 1) == 'F') && countDots == 0){
        return (false);
    }
    if (countDots > 1 || str.at(0) == '.' || str.at(strLen -1) == '.'){
        return (false);
    }
    inputNbr = std::strtold(str.c_str(), NULL);
    if (inputNbr > std::numeric_limits<float>::max() || inputNbr < std::numeric_limits<float>::min()){
      return (false);
    }
     // STR TO FLOAT
    str.erase(str.length() - 1, 1);
    result.f = std::atof(str.c_str()); // I have to print 'f' after this one!
    return (true);
}

// ----- IS DOUBLE -----
bool LiteralDetector::isDouble (std::string str, ScalarConverter::convRes &result){
    int countDots = 0;
    int strLen = str.length();

    strToLow(str);
    int i = 0;
    
    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf"){
      if (str == "nan")
        result.d = NAN;
      if (str == "+inf" || str == "inf")
        result.d = INFINITY;
      if (str == "-inf")
        result.d = -INFINITY;
      result.specialDouble = true;
      return true;
    }    
    if (str.at(i) == '-'|| str.at(i) == '+'){
        i++;
    }

    for (; i < strLen; ++i){
        if (str.at(i) == '.'){
            countDots++;
        }
        if (str.at(i) != '.' && !isdigit(str.at(i))){
          return (false);
        }
    }
    if (countDots > 1 || str.at(0) == '.'|| str.at(strLen -1) == '.'){
        return (false);
    }
    // STR TO DOUBLE
    std::stringstream ss(str);
    result.d  = 0.0;
    ss >> result.d;
    return (true);
}


