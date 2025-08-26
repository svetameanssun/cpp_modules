#include "../include/ScalarConverter.hpp"
#include "../include/LiteralDetector.hpp"

/*
  Syntax of static_cast
  static_cast <dest_type> (source);

 */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
  (void)other;
}
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other){
  (void)other;
  return *this;
}
ScalarConverter::~ScalarConverter() {}

std::ostream& operator<<(std::ostream& os, const struct ScalarConverter::convertResult& result){
  // CHAR --> NON-PRINTABLE / IMPOSSIBLE / PRINTABLE /
  os << "char: ";
    if (result.charFlag == 0){
      os << "Non displayable\n";
    }
    else if (result.charFlag == -1){
      os << "Impossible\n";
    }
    else{
      os << result.c << "\n";
    }

    // INT --> CONDITION IF INT IS IMPOSSIBLE
    os << "int: ";
    if (result.intFlag == true){
      os << result.i << "\n";
    }
    else{
      os << "Impossible\n";
    }
    // FLOAT --> CONDITION inff, nanf, etc 
    os << "float: ";
    os << result.f << "f" << "\n";
    
    // DOUBLE -->  CONDITION inf, nan, etc 
    os << "double: ";
    os << result.d << "\n";
    return os;
}

void ScalarConverter::convert(const std::string &literal){
  ScalarConverter::convRes result;
  std::string str;
  
  if (LiteralDetector::isChar(literal, result)){
    
    //CHAR TO INT
    result.i = static_cast<int>(result.c);

    // INT TO FLOAT
    result.f = static_cast<float>(result.i);
    
    //FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);
    std::cout << "It is CHAR!\n";
  }
  else if (LiteralDetector::isInt(literal, result)){

      // INT TO CHAR with conditions
      if (result.i >= 33 && result.i <= 126){
        result.c = static_cast<char>(result.i); // normal
        result.charFlag = 1;
      }
      else if(result.i < 33 || result.i == 127)
      {
        result.c = static_cast<char>(result.i); // Non displayable
        result.charFlag = 0;
      } 
      else{
        result.c = 0;
        result.charFlag = -1;
      }
      // INT TO FLOAT
        result.f = static_cast<float>(result.i);

      // FLOAT TO DOUBLE
        result.d = static_cast<double>(result.f);
      std::cout << "It is INT!\n";
    
  }
  else if (LiteralDetector::isFloat(literal, result)){
    
    //FLOAT TO INT
    if (result.f > (long)std::numeric_limits<int>::max() || result.f < (long)std::numeric_limits<int>::min()){
      result.intFlag = false;
      result.i = 0;
    }
    else{
      result.intFlag = true;
      result.i = static_cast<int>(result.f);
    }

    // FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);

    // INT TO CHAR
      if (result.i >= 33 && result.i <= 126)
        result.c = static_cast<char>(result.i); // normal
      else if(result.i < 33 || result.i == 127)
      {
        result.c = static_cast<char>(result.i); // Non displayable
        result.charFlag = 0;
      } 
      else{
        result.c = 0;
        result.charFlag = -1;
      }
      std::cout << "It is Float!\n";
  }
  else if (LiteralDetector::isDouble(literal, result)){
    
    // DOUBLE TO INT
    if (result.d > (long)std::numeric_limits<int>::max() || result.d < (long)std::numeric_limits<int>::min()){
      result.intFlag = false;
      result.i = 0;
    }
    else{
      result.intFlag = true;
      result.i = static_cast<int>(result.d);
    }

    // DOUBLE TO FLOAT
    //check the size???
    result.f = static_cast<float>(result.d);

    // INT TO CHAR
      if (result.i >= 33 && result.i <= 126)
        result.c = static_cast<char>(result.i); // normal
      else if(result.i < 33 || result.i == 127)
      {
        result.c = static_cast<char>(result.i); // Non displayable
        result.charFlag = 0;
      } 
      else{
        result.c = 0;
        result.charFlag = -1;
      }
      std::cout << "It is DOuble!\n";
    
  }
  //print result!!!
  std::cout << result;

}


