#include "../include/ScalarConverter.hpp"
#include "../include/LiteralDetector.hpp"
#include "../include/ExceptWrongInp.hpp"

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
    else {
      os << "Impossible\n";
    }
    // FLOAT --> CONDITION inff, nanf, etc
    os << "float: ";
    os << std::fixed << std::setprecision(1) <<result.f;
    os << "f";
    os<< "\n";
    
    // DOUBLE -->  CONDITION
    os << "double: ";
    os<< std::fixed<< std::setprecision(1) <<result.d;
    os<< "\n";
    return (os);
}

void ScalarConverter::convert(const std::string &literal){
  ScalarConverter::convRes result;
  std::string str;
  
  if (LiteralDetector::isChar(literal, result)){
    
    //CHAR TO INT
    result.i = static_cast<int>(result.c);
    result.intFlag = true;
    std::cout << "MY INT: " << result.i << "\n";

    // INT TO FLOAT
    result.f = static_cast<float>(result.i);
    
    //FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);
    std::cout << "It is CHAR!\n";
  }
  else if (LiteralDetector::isInt(literal, result)){

      // INT TO CHAR with conditions
      result.charFlag = charStatus(result.i);
      if (result.i >= 0 && result.i <= 127){
        result.c = static_cast<char>(result.i);
      } 
      else{
        result.c = 0; 
      }
      // FLOAT TO DOUBLE
      result.d = static_cast<double>(result.i);
      std::cout << "It is INT!\n";

      // INT TO FLOAT
      
      result.f = static_cast<float>(result.d);

    
  }
  else if (LiteralDetector::isFloat(literal, result)){
    
    //FLOAT TO INT
    result.intFlag = intStatus(result.f);
    if (result.specialFloat == true)
      result.intFlag = false;
    result.i = static_cast<int>(result.f);

    // FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);

    // INT TO CHAR
      result.charFlag = charStatus(result.i);
      if (result.i >= 0 && result.i <= 127){
        result.c = static_cast<char>(result.i);
      } 
      else{
        result.c = 0; 
      }
      std::cout << "It is Float!\n";
  }
  else if (LiteralDetector::isDouble(literal, result)){
    
    // DOUBLE TO INT
    result.intFlag = intStatus(result.d);
    if (result.specialDouble == true)
      result.intFlag = false;
    result.i = static_cast<int>(result.d);


    // DOUBLE TO FLOAT
    //check the size???
    result.f = static_cast<float>(result.d);

    // INT TO CHAR
      result.charFlag = charStatus(result.i);
      if (result.i >= 0 && result.i <= 127){
        result.c = static_cast<char>(result.i);
      } 
      else{
        result.c = 0; 
      }
      std::cout << "It is Double!\n";
    
  }
  else{
    throw ExceptWrongInp();
  }
  //print result!!!
  std::cout << result;

}


