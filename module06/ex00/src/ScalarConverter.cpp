/*class ScalarConverter{
  public:
    typedef struct ConvertResult{
      char c;
      int i;
      float f;
      double d;
    };
    static void convert(const std::string &literal);
  private:
    ScalarConverter(){};
    ~ScalarConverter(){};
};*/

#include "ScalarConverter.hpp"
#include "LiteralDetectorr.hpp"

void convert(const std::string &literal){
  ScaralConvert::ConvertResult result;
  
  if (LiteralDetector::isChar(literal)){
      //s
  }
  else if (LiteralDetector::isInt(literal)){
    
  }
  else if (LieralDetector::isFloat()){
    
  }
  else if (LiteralDetector::isDouble()){
    
  }


