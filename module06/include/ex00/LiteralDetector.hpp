#ifndef LITERALDETECTOR_HPP
#define LITERALDETECTOR_HPP

class LiteralDetector{
  public:
    static bool isChar(char *str);
    static bool isInt(char *str);
    static bool isFloat(char *str);
    static bool isDouble(char *str);
  private:
    LiteralDetector(){};
    ~LiteralDetector(){};    
};

#endif
