#include "../include/ScalarConverter.hpp"
#include "../include/LiteralDetector.hpp"


/*
  Syntax of static_cast
  static_cast <dest_type> (source);

 */
void ScalarConverter::convert(const std::string &literal){
  ScalarConverter::convRes result;
  std::string str;
  
  if (LiteralDetector::isChar(literal)){
    // STR TO CHAR
    if (literal.length() == 3)
      result.c = literal[1];
    else{
      result.c = literal[0];
    }
    //CHAR TO INT
    result.i = static_cast<int>(result.c);

    // INT TO FLOAT
    result.f = static_cast<float>(result.i);
    
    //FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);
  }
  else if (LiteralDetector::isInt(literal)){
      // STR TO INT
      result.i = atoi(literal.c_str());
    
      // INT TO CHAR
      if(result.i < 33 || result.i > 126)
        result.c = 0; //flag for future processing
      else
        result.c = static_cast<char>(result.i);

      // INT TO FLOAT
        result.f = static_cast<float>(result.i);

      // FLOAT TO DOUBLE
        result.d = static_cast<double>(result.f);

    
  }
  else if (LiteralDetector::isFloat(literal)){
    //STR TO FLOAT
    str = literal;
    str.erase(literal.length() - 1, 1);
    result.f = std::atof(str.c_str()); // I have to print 'f' after this one!


    //FLOAT TO INT
    // check the size???
    result.i = static_cast<int>(result.f);

    // FLOAT TO DOUBLE
    result.d = static_cast<double>(result.f);

    // INT TO CHAR
      if(result.i < 33 || result.i > 126)
        result.c = 0; //flag for future processing
      else
        result.c = static_cast<char>(result.i);
    
  }
  else if (LiteralDetector::isDouble(literal)){
    // STR TO DOUBLE
    str = literal;
    std::stringstream ss(str);
    result.d  = 0.0;
    ss >> result.d;

    // DOUBLE TO INT
    // check the size???
    result.i = static_cast<int>(result.d);

    // DOUBLE TO FLOAT
    //check the size???
    result.f = static_cast<float>(result.d);

    // INT TO CHAR
      if(result.i < 33 || result.i > 126)
        result.c = 0; //flag for future processing
      else
        result.c = static_cast<char>(result.i);
    
  }

}
